cmake_minimum_required(VERSION 3.15)
project(Tests_PrimeNumbersGenerator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tests_PrimeNumbersGenerator main.cpp tests.cpp GeneratePrimeNumbersSet.cpp GeneratePrimeNumbersSet.h)