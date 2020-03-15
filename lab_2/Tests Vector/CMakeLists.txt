cmake_minimum_required(VERSION 3.15)
project(Tests_Vector)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tests_Vector main.cpp tests.cpp ProcessVector_7.cpp)