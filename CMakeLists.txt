# CMAKE VERSION REQUIRED
cmake_minimum_required(VERSION 3.26)

# PROJECT NAME
project(advanced_cpp_bhcc)

# C++ VERSION
set(CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE TRUE)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API aa1f7df0-828a-4fcd-9afc-2dc80491aca7)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fmodules-ts")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# READING ASSIGNMENTS
add_executable(assignment_1
        src/assignment/1/Student.cpp
        src/assignment/1/Student.h
        src/assignment/1/Database.cpp
        src/assignment/1/Database.h
        src/assignment/1/TestDatabase.cpp)

add_executable(assignment_2_1
        src/assignment/ZhuojianChenCh11HW1/bookshelf.cppm
        src/assignment/ZhuojianChenCh11HW1/testStoreShelf.cpp
)


# UNITS
add_executable(unit_1_1 src/unit/1_1/testNamespaces.cpp src/unit/1_1/chinaNamespace.h src/unit/1_1/americaNamespace.h)
add_executable(unit_1_2 src/unit/1_2/Unit1Project2.cpp)
add_executable(unit_1_3
        src/unit/1_3/Unit1Project3.cpp)

# TESTS
add_executable(test_any src/test/any.cpp)