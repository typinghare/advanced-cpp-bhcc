# CMAKE VERSION REQUIRED
cmake_minimum_required(VERSION 3.26)

# PROJECT NAME
project(advanced_cpp_bhcc)

# C++ VERSION
set(CMAKE_CXX_STANDARD 20)

# EXECUTABLES
add_executable(advanced_cpp_bhcc main.cpp)

# READING ASSIGNMENTS
add_executable(assignment_1 src/assignment/1/Student.cpp
        src/assignment/1/Student.h
        src/assignment/1/Database.cpp
        src/assignment/1/Database.h
        src/assignment/1/TestDatabase.cpp)