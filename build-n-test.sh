#!/bin/bash


rm -rf build


mkdir build
cmake -S source -B build
cmake --build build --config=Debug


cd build/bin
./demoapplication JohnDow 44