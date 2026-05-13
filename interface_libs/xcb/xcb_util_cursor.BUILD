# BUILD overlay for the @xcb_util_cursor http_archive declared in
# qt-bazel's MODULE.bazel. Builds xcb-util-cursor 0.1.5 as a static
# cc_library so the Qt xcb platform plugin doesn't dlopen
# libxcb-cursor.so.0 from the host.

load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "cursor",
    srcs = [
        "cursor/cursor.c",
        "cursor/cursor.h",
        "cursor/load_cursor.c",
        "cursor/parse_cursor_file.c",
        "cursor/shape_to_id.c",
    ],
    hdrs = ["cursor/xcb_cursor.h"],
    copts = [
        # asprintf() is a GNU extension; glibc gates it behind _GNU_SOURCE.
        "-D_GNU_SOURCE",
        "-DXCURSORPATH='\"~/.icons:/usr/share/icons:/usr/share/pixmaps:/usr/X11R6/lib/X11/icons\"'",
    ],
    include_prefix = "xcb",
    strip_include_prefix = "cursor",
    visibility = ["@qt-bazel//interface_libs/xcb:__pkg__"],
    deps = [
        "@libxcb",
        "@qt-bazel//interface_libs/xcb:xcb_hdrs",
    ],
)
