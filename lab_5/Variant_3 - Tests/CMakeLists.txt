cmake_minimum_required(VERSION 3.16)
project(Variant_3___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Variant_3___Tests main.cpp ../Variant_3/CRational.cpp ../Variant_3/CRational.h CRational_tests.cpp)