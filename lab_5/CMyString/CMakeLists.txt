cmake_minimum_required(VERSION 3.16)
project(CMyString)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 20)

add_executable(CMyString main.cpp CMyString.cpp CMyString.h)