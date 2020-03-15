cmake_minimum_required(VERSION 3.15)
project(Tests_Html_Decode)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tests_Html_Decode main.cpp Tests.cpp decode.cpp Decode.h)