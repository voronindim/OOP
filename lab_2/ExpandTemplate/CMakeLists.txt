cmake_minimum_required(VERSION 3.15)
project(ExpandTemplate)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 20)

add_executable(ExpandTemplate main.cpp ExpandTemplate.cpp ExpandTemplate.h)