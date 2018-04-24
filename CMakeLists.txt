cmake_minimum_required(VERSION 3.8)
project(Attendance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ./code/main.cpp ./code/Faculty.cpp ./code/Faculty.h ./code/Student.cpp ./code/Student.h ./code/Interface_handler.cpp ./code/Interface_handler.h ./code/Admin.cpp ./code/Admin.h ./code/User.cpp ./code/User.h ./code/Database_handler.cpp ./code/Database_handler.h)
add_executable(AMS ${SOURCE_FILES})