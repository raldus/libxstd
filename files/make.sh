#!/bin/bash

pushd .. > /dev/null

mkdir -p bin
mkdir -p build

cmake --build build -- -j3 $1 $2 $3 $4 $5

popd > /dev/null

