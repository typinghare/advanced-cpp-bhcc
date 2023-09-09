# CMAKE VERSION REQUIRED
cmake_minimum_required(VERSION 3.26)

# PROJECT NAME
project(advanced_cpp_bhcc)

# C++ VERSION
set(CMAKE_CXX_STANDARD 20)

# READING ASSIGNMENTS
add_executable(assignment_1 src/assignment/1/Student.cpp
        src/assignment/1/Student.h
        src/assignment/1/Database.cpp
        src/assignment/1/Database.h
        src/assignment/1/TestDatabase.cpp
        src/unit/1_2/Unit1Project2.cpp
        src/test/any.cpp)

# UNITS
add_executable(unit_1_1 src/unit/1_1/testNamespaces.cpp src/unit/1_1/chinaNamespace.h src/unit/1_1/americaNamespace.h)
add_executable(unit_1_2 src/unit/1_2/Unit1Project2.cpp)

# TESTS
add_executable(test_any src/test/any.cpp)