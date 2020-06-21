cmake_minimum_required(VERSION 3.16)
project(StringList)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(StringList main.cpp StringList.cpp StringList.h)