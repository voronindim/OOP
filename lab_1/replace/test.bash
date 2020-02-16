#!/bin/bash
exec "cmake-build-release/replace" "input1.txt" "output.txt" "Dog" "**"
echo $?

