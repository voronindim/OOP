cmake_minimum_required(VERSION 3.16)
project(StringList___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(StringList___Tests main.cpp ../StringList/StringList.cpp ../StringList/StringList.h StringList_tests.cpp)