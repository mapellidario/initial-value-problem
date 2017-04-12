#!/bin/zsh

rm -rfv build
mkdir build
cd build
cmake ..
make
cd ..
