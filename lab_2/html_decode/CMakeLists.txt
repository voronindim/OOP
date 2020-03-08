cmake_minimum_required(VERSION 3.15)
project(html_decode)

set(CMAKE_CXX_STANDARD 20)

add_executable(html_decode main.cpp Decode.h decode.cpp)