cmake_minimum_required(VERSION 3.15)
project(NewCar)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewCar main.cpp IManualGearVehicle.cpp IManualGearVehicle.h CCar.cpp CCar.h CAutoPilot.cpp CAutoPilot.h ControlForCCar.cpp ControlForCCar.h ControlAutoPilot.cpp ControlAutoPilot.h)