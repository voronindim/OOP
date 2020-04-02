cmake_minimum_required(VERSION 3.15)
project(Tests_Dictionary)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tests_Dictionary main.cpp tests.cpp ../dictionary/vocabulary.cpp)