cmake_minimum_required(VERSION 3.15)
project(Car___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car___Tests main.cpp ../Car/CCar.cpp ../Car/CCar.h tests.cpp)