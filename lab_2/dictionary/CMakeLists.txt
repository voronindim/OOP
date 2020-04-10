cmake_minimum_required(VERSION 3.15)
project(dictionary)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(dictionary main.cpp vocabulary.cpp vocabulary.h)