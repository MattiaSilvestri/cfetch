#!/usr/bin/env sh

readonly BIN="/usr/bin"

cd build
cmake ..
make
cd ..

# Move binary to path
sudo mv ./bin/cfetch $BIN

printf "Installation succesfull!\n"
