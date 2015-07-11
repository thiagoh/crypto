#!/bin/bash

if [ ! -f cmocka-1.0.1.tar.xz ]; then
	wget https://cmocka.org/files/1.0/cmocka-1.0.1.tar.xz
	rm -rf cmocka-1.0.1
	tar xf cmocka-1.0.1.tar.xz
fi

rm -rf cmocka-build || true
mkdir cmocka-build

rm -rf build || true
mkdir build

cd cmocka-build
cmake ../cmocka-1.0.1
make

cd ../build

cmake -G"Eclipse CDT4 - Unix Makefiles" -D_ECLIPSE_VERSION=4.5 -D CMAKE_BUILD_TYPE=Debug ..
#cmake --debug-output .. 

mv .project ..
mv .cproject ..
make -j 4 
ctest --output-on-failure .
