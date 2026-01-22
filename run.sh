#!/usr/bin/env sh

set -xe

g++ -std=gnu++17 -Wall -Wextra "$1" && ./a.out
