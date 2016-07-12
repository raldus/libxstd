#!/bin/bash

pushd .. > /dev/null

find ../src -name "*.cpp" -print -exec clang-format -i {} \; -or -name "*.h" -print -exec clang-format -i {} \;

popd .. > /dev/null

