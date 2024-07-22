#!/bin/sh

set -xe

mkdir -p bin

SRC="src/*.c"
BIN="-o bin/chafacad"
FRAMEWORKS="-framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL"
INCLUDES="-I include/"
RAYLIB="lib/libraylib.a"

clang $SRC $BIN $FRAMEWORKS $INCLUDES $RAYLIB
