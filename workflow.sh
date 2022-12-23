#!/usr/bin/env zsh
# Build the project
# Path: build.sh

cmake -B build
cd build
make
./Fast
