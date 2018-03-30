cmake_minimum_required(VERSION 3.8)
project(Attendance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Faculty.cpp Faculty.h Student.cpp Student.h Interface_handler.cpp Interface_handler.h Admin.cpp Admin.h User.cpp User.h Database_handler.cpp Database_handler.h)
add_executable(Attendance ${SOURCE_FILES})