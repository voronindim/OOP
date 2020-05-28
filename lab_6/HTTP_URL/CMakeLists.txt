cmake_minimum_required(VERSION 3.16)
project(HTTP_URL)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 20)

add_executable(HTTP_URL main.cpp CHttpUrl.cpp CHttpUrl.h CUrlParsingError.cpp CUrlParsingError.h)