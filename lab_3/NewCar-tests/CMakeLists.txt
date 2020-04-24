cmake_minimum_required(VERSION 3.15)
project(NewCar_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewCar_tests main.cpp CCarTests.cpp ../NewCar/CCar.cpp ../NewCar/CCar.h ../NewCar/ControlForCCar.cpp ../NewCar/ControlForCCar.h ControlForCCarTests.cpp MockedCar.cpp MockedCar.h AutoPilotTests.cpp ../NewCar/CAutoPilot.cpp ../NewCar/CAutoPilot.h ../NewCar/ControlAutoPilot.cpp ../NewCar/ControlAutoPilot.h ControlForCAutoPilotTests.cpp)