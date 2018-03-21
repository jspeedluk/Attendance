cmake_minimum_required(VERSION 3.8)
project(Attendance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp attendance_management.cpp attendance_management.h)
add_executable(Attendance ${SOURCE_FILES})