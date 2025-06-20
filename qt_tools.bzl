"""Starlark rule for running moc on Q_OBJECT files."""

def _moc_impl(ctx):
    flags = [ctx.file.src.path]
    flags += ["-I."]
    flags += ["-I" + ctx.file.src.path[:ctx.file.src.path.rfind("/")]]

    # In an ideal world we would have grabbed these from the _internal_deps
    # rule, but skylark doesn't want to expose the copts flag on the targets,
    # so we have to pass them in separately.
    all_include_directories_list = [flag[2:] for flag in ctx.attr.copts if flag.startswith("-I")]
    all_defines_list = [flag[2:] for flag in ctx.attr.copts if flag.startswith("-D")]

    # Visit all deps with the "cc" provider collecting their includes and
    # transitive headers.
    transitive_headers = []
    transitive_dep_headers = []
    include_directories = []
    defines = []
    for target in ctx.attr.deps:
        if CcInfo in target:
            include_directories += [
                target[CcInfo].compilation_context.includes,
                target[CcInfo].compilation_context.quote_includes,
                target[CcInfo].compilation_context.system_includes,
            ]
            defines.append(target[CcInfo].compilation_context.defines)

            if target.label.package.startswith("qt_source"):
                # It's a qt dependency, so just grab the library headers.
                transitive_headers.append(target[CcInfo].compilation_context.headers)
            elif ctx.attr.transitive_deps:
                # Borrowed from devtools/clif/python/clif_build_rule.bzl.
                # We could use full transitive_headers list, but that runs into
                # Forge 40K files limit. We filter headers to just those contained
                # in the current package, and add //base and //third_party/absl/...
                # for lock annotations.
                #
                # NOTE: this set appears to work for all current TAP tests, but is
                # in no way guaranteed to be correct. If you get strange 'moc'
                # errors or other build problems, try uncommenting the next line,
                # and contact OWNERS if that helps.
                #
                # deptargets += list(target.cc.transitive_headers)
                for header in target[CcInfo].compilation_context.headers.to_list():
                    if (target.label.package in header.path):
                        transitive_dep_headers.append(header)
    all_include_directories = depset(direct = all_include_directories_list, transitive = include_directories)
    all_defines = depset(direct = all_defines_list, transitive = defines)
    deptargets = depset(direct = ctx.files.resource_srcs + transitive_dep_headers, transitive = transitive_headers)

    if not ctx.attr.show_warnings:
        # Suppress warnings and notes from moc. moc outputs a note each time a
        # file doesn't have anything to moc-ify, which pollutes the blaze output;
        # the fix is to move the source file from moc_srcs to srcs, but this
        # isn't something that clients should need to worry about.
        flags += ["--no-warnings"]

    # Generate the flags for moc.
    for include in all_include_directories.to_list():
        flags += ["-I" + include]
    for define in all_defines.to_list():
        flags += ["-D" + define]

    if ctx.attr.rewrite_includes:
        # We use the -p flag to rewrite the generated include lines to be
        # relative to google3/.
        flags += ["-p" + ctx.file.src.dirname]
    flags += ["-o" + ctx.outputs.out.path]

    ctx.actions.run(
        outputs = [ctx.outputs.out],
        inputs = depset(direct = [ctx.file.src], transitive = [deptargets]),
        arguments = flags + ctx.attr.moc_opts,
        progress_message = "Generating MOC code from %s" % str(ctx.file.src.path),
        executable = ctx.executable._moc_binary,
    )

# Private skylark rule to invoke moc on the given src.  Rather than
# implementing this as a simple genrule, we use a skylark rule so we can
# collect extra include directories that might have been specified by
# cc_library dependencies.
moc_gen = rule(
    attrs = {
        "deps": attr.label_list(),
        "src": attr.label(allow_single_file = True),
        "resource_srcs": attr.label_list(allow_files = True),
        "copts": attr.string_list(),
        "moc_opts": attr.string_list(default = []),
        "out": attr.output(),
        "show_warnings": attr.bool(default = False),
        "rewrite_includes": attr.bool(default = True),
        "transitive_deps": attr.bool(default = True),
        "_moc_binary": attr.label(
            executable = True,
            allow_files = True,
            default = Label("//qt_source:moc"),
            cfg = "exec",
        ),
    },
    fragments = ["cpp"],
    implementation = _moc_impl,
)