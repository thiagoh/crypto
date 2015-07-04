#!/bin/bash

current_dir=$(pwd)

rm -rf $current_dir/build || true
mkdir $current_dir/build
cd $current_dir/build

#cmake --debug-output .. 

cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ..

make -j 4 

