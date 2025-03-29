#!/usr/bin/env sh

set -xe
g++ -o snowflake ./snowflake.cpp -I./depend/raylib/include/ -L./depend/raylib/lib -l:libraylib.a -lm
