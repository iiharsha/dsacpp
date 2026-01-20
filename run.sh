#!/usr/bin/env sh

set -xe

g++ -std=gnu++17 -Wall "$1" && ./a.out
