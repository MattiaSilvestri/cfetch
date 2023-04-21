#!/usr/bin/env sh

readonly BIN="/usr/bin"

mkdir build
mkdir bin
cd build
cmake ..
make
cd ..

# Move binary to path
sudo mv ./bin/cfetch $BIN

# Clean installation files
rm -r build && rm -r bin
