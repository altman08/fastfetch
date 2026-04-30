#!/usr/bin/env bash

set -e

# 为merlin路由器编译
rm -rf build
mkdir -p build/
cd build/

TOOLCHAIN=/opt/toolchains/crosstools-arm-gcc-9.2-linux-4.19-glibc-2.30-binutils-2.32

cmake \
    -DCMAKE_C_COMPILER="${TOOLCHAIN}/bin/arm-linux-gcc" \
    -DCMAKE_CXX_COMPILER="${TOOLCHAIN}/bin/arm-linux-g++" \
    -DCMAKE_SYSTEM_NAME=Linux \
    -DCMAKE_SYSTEM_PROCESSOR=armv7l \
    -DCMAKE_FIND_ROOT_PATH="${TOOLCHAIN}" \
    -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
    -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
    -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
    -DCMAKE_BUILD_TYPE=MinSizeRel \
    -DBUILD_FLASHFETCH=OFF \
    -DSET_TWEAK=OFF \
    -DINSTALL_LICENSE=OFF \
    -DENABLE_ZLIB=OFF \
    -DENABLE_ELF=OFF \
    -DENABLE_LIBZFS=OFF \
    -DENABLE_DIRECTX_HEADERS=OFF \
    -DENABLE_GIO=OFF \
    ..

kernel_name="$(uname -s)"

case "${kernel_name}" in
    "Linux" | "MINGW"*)
        cmake_build_args=("-j$(nproc)")
        ;;
    "Darwin" | *"BSD" | "DragonFly")
        cmake_build_args=("-j$(sysctl -n hw.ncpu)")
        ;;
    *)
        cmake_build_args=()
        ;;
esac

cmake --build . --target fastfetch "${cmake_build_args[@]}"

"${TOOLCHAIN}/bin/arm-linux-strip" ./fastfetch
