#!/bin/bash

echo "Creating build directory" && mkdir -p build && cd build && \
echo "Generating Makefile" && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && \
echo "Building project" && cmake --build .