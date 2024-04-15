#!/bin/sh

set -xe

mkdir -p bin

FLAGS="-Wall -Wextra -pedantic"
FRAMEWORKS="-framework Cocoa -framework OpenGL -framework IOKit"
BIN="-o bin/chafacad"
SRC="src/main.c"
INCLUDE="-I /opt/homebrew/Cellar/glfw/3.4/include -I /opt/homebrew/Cellar/glew/2.2.0_1/include"
LINKS="-L /opt/homebrew/Cellar/glfw/3.4/lib -L /opt/homebrew/Cellar/glew/2.2.0_1/lib"
LIBS="-l glfw3 -l GLEW"

clang $FLAGS $FRAMEWORKS $BIN $SRC $INCLUDE $LINKS $LIBS
