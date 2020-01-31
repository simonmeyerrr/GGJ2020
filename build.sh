#!/bin/bash

echo "Os type:" $OSTYPE

if [[ "$OSTYPE" == "win32" ]]; then
  echo "Use visual studio to build this project by your own"
else
  echo "Creating build directory" && mkdir -p build && cd build && \
  echo "Generating Makefile" && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && \
  echo "Building project" && cmake --build .
fi