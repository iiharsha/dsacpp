#!/usr/bin/env sh

set -xe

g++ -std=gnu++17 -Wall -Wextra -g -O0 "$1" -o solution && ./solution
