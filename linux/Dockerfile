# Dockerfile to build Qt 6.9.0 from source on Ubuntu 22.04 (Jammy Jellyfish)

# Use the official Ubuntu 22.04 base image
FROM ubuntu:22.04

# Set environment variables to allow for non-interactive installation of packages
ENV DEBIAN_FRONTEND=noninteractive

# Set versions and configurations
ARG QT_VERSION=6.9.1
ARG QT_INSTALL_DIR=/opt/qt6

# Update package lists and install essential build tools and dependencies
# This is a comprehensive list required for a standard Qt build.
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    ninja-build \
    git \
    wget \
    perl \
    python3 \
    libssl-dev \
    # X11 and OpenGL dependencies
    libfontconfig1-dev \
    libfreetype-dev \
    libgtk-3-dev \
    libx11-dev \
    libx11-xcb-dev \
    libxcb-cursor-dev \
    libxcb-glx0-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-randr0-dev \
    libxcb-render-util0-dev \
    libxcb-shape0-dev \
    libxcb-shm0-dev \
    libxcb-sync-dev \
    libxcb-util-dev \
    libxcb-xfixes0-dev \
    libxcb-xkb-dev \
    libxcb1-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libxrender-dev \
    # Multimedia dependencies
    libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    libasound2-dev \
    # Other dependencies
    libdbus-1-dev \
    libfontconfig-dev \
    libfreetype-dev \
    libicu-dev \
    libjpeg-dev \
    libpng-dev \
    libz-dev \
    libsqlite3-dev \
    libvulkan-dev \
    # Clean up apt cache to reduce image size
    && rm -rf /var/lib/apt/lists/*

# Set up a working directory
WORKDIR /tmp

# Download the Qt source code
RUN QT_MAJOR_MINOR_VERSION=$(echo "${QT_VERSION}" | cut -d. -f1,2) && \
    wget https://download.qt.io/official_releases/qt/${QT_MAJOR_MINOR_VERSION}/${QT_VERSION}/single/qt-everywhere-src-${QT_VERSION}.tar.xz && \
    # Extract the source code
    tar xf qt-everywhere-src-${QT_VERSION}.tar.xz && \
    # Remove the downloaded archive
    rm qt-everywhere-src-${QT_VERSION}.tar.xz

# Enter the source directory and configure the build
WORKDIR /tmp/qt-everywhere-src-${QT_VERSION}

# Configure the Qt build.
# -prefix: The directory where Qt will be installed.
# -opensource: We are using the open-source version.
# -confirm-license: Automatically confirms the open-source license.
# -nomake examples/tests: Speeds up the build by not building examples and tests.
# You can add or remove modules from the -skip list as needed.
RUN ./configure \
    -static \
    -release \
    -prefix ${QT_INSTALL_DIR} \
    -opensource \
    -confirm-license \
    -nomake examples \
    -nomake tests \
    -skip qtwebengine \
    -skip qt3d \
    -skip qtquick3d \
    -skip qtgraphs \
    -skip qtvirtualkeyboard \
    -skip qtwayland \ 
    -skip qtquick3dphysics

# Build Qt using the number of available processor cores
RUN cmake --build . --parallel $(nproc)

# Install Qt
RUN cmake --install .

RUN tar -czvf /tmp/qt6-static.tar.gz -C /opt/qt6 .