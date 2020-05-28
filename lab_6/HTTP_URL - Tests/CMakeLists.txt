cmake_minimum_required(VERSION 3.16)
project(HTTP_URL___Tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(HTTP_URL___Tests main.cpp ../HTTP_URL/CHttpUrl.h ../HTTP_URL/CHttpUrl.cpp ../HTTP_URL/CUrlParsingError.h ../HTTP_URL/CUrlParsingError.cpp CHttpUrl_tests.cpp)