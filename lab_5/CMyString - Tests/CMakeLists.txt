cmake_minimum_required(VERSION 3.16)
project(CMyString___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(CMyString___Tests main.cpp CMyString_tests.cpp ../CMyString/CMyString.cpp ../CMyString/CMyString.h)