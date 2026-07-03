#!/bin/sh

set -xe

# add `-DBUILD_AS_LIBRARY` if built as library
CFLAGS="-Wall -Wextra -pedantic"
cc $CFLAGS -o fakeua fakeua.c -lcurl
