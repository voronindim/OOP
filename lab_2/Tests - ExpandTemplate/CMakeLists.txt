cmake_minimum_required(VERSION 3.15)
project(Tests___ExpandTemplate)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tests___ExpandTemplate main.cpp tests.cpp ../ExpandTemplate/ExpandTemplate.cpp)