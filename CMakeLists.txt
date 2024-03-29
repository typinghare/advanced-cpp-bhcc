# CMAKE VERSION REQUIRED
cmake_minimum_required(VERSION 3.26)

# PROJECT NAME
project(advanced_cpp_bhcc)

# C++ VERSION
set(CMAKE_CXX_STANDARD 20)

# READING ASSIGNMENTS
add_executable(assignment_1
        src/assignment/1/Student.cpp
        src/assignment/1/Student.h
        src/assignment/1/Database.cpp
        src/assignment/1/Database.h
        src/assignment/1/TestDatabase.cpp
)

add_executable(assignment_2_1
        src/assignment/2/ZhuojianChenCh11HW1/testStoreShelf.cpp
        src/assignment/2/ZhuojianChenCh11HW1/bookshelf.cppm
)
add_executable(assignment_2_2
        src/assignment/2/ZhuojianChenCh11HW2/testStoreShelf.cpp
        src/assignment/2/ZhuojianChenCh11HW2/Item.cppm
        src/assignment/2/ZhuojianChenCh11HW2/DisplayCard.cppm
)
add_executable(assignment_2_3
        src/assignment/2/ZhuojianChenCh11HW3/testStoreShelf.cpp
        src/assignment/2/ZhuojianChenCh11HW3/bookshelf.cppm
        src/assignment/2/ZhuojianChenCh11HW3/Item.cppm
        src/assignment/2/ZhuojianChenCh11HW3/DisplayCard.cppm
)
add_executable(assignment_2_4
        src/assignment/2/ZhuojianChenCh11HW4/testStoreShelf.cpp
        src/assignment/2/ZhuojianChenCh11HW4/bookshelf.cppm
        src/assignment/2/ZhuojianChenCh11HW4/DisplayCard.cppm
        src/assignment/2/ZhuojianChenCh11HW4/Item.cppm
        src/assignment/2/ZhuojianChenCh11HW4/Internals.cppm
        src/assignment/2/ZhuojianChenCh11HW4/InternalsImplement.cppm
)

add_executable(assignment_3
        src/assignment/3/Amorphous.h
        src/assignment/3/TestShapes.cpp
        src/assignment/3/Rectangle.h
        src/assignment/3/Circle.h
        src/assignment/3/Shape.h
        src/assignment/3/Square.h
        src/assignment/3/Triangle.h
)

add_executable(assignment_4
        src/assignment/4/BinaryLabBase.cpp
)

add_executable(assignment_7
        src/assignment/7/user/User.cpp
        src/assignment/7/user/User.h
        src/assignment/7/user/SuperUser.cpp
        src/assignment/7/user/SuperUser.h
        src/assignment/7/user/TestUsers.cpp
        src/assignment/7/user/Secure.h
        src/assignment/7/user/Secure.cpp
)

add_executable(assignment_11
        src/assignment/11/Student.h
        src/assignment/11/Student.cpp
        src/assignment/11/Application.h
        src/assignment/11/Application.cpp
        src/assignment/11/TestApplication.cpp
)

add_executable(assignment_12_dated
        src/assignment/12_dated/Hashtable.cpp
        src/assignment/12_dated/Hashtable.h
        src/assignment/12_dated/TestStudentCourse.cpp
        src/assignment/12_dated/StudentCourse.cpp
        src/assignment/12_dated/StudentCourse.h
)

add_executable(assignment_12
        src/assignment/12/HashTable.cpp
        src/assignment/12/HashTable.h
        src/assignment/12/Student.cpp
        src/assignment/12/Student.h
        src/assignment/12/TestStudent.cpp
)

# UNITS
add_executable(unit_1_1 src/unit/1_1/testNamespaces.cpp src/unit/1_1/chinaNamespace.h src/unit/1_1/americaNamespace.h)
add_executable(unit_1_2 src/unit/1_2/Unit1Project2.cpp)
add_executable(unit_1_3 src/unit/1_3/Unit1Project3.cpp)
add_executable(unit_4_1 src/unit/4_1/Unit4Project1.cpp)
add_executable(unit_4_2 src/unit/4_2/TestWidgets.cpp
        src/unit/4_2/settings.h
        src/unit/4_2/binaryOperations.cpp)
add_executable(unit_7_1
        src/unit/7_1/Matrix.cpp
        src/unit/7_1/Matrix.h
        src/unit/7_1/TestMatrix.cpp
)

add_executable(unit_7_2
        src/unit/7_2/Cylinder.cpp
        src/unit/7_2/Cylinder.h
        src/unit/7_2/CylinderGrid.cpp
        src/unit/7_2/CylinderGrid.h
        src/unit/7_2/TestCylinderGrid.cpp
)

# TESTS
add_executable(test_any src/test/any.cpp
        src/test/IntIterator.h)
add_executable(test_bitwise_discussion src/test/bitwise_discussion/Spiral.cpp)
add_executable(bitwise_on_int src/test/bitwise_on_int/BitwiseOnInt.cpp)
add_executable(dependency_injection src/test/dependency_injection/classes.h src/test/dependency_injection/TestDependencyInjection.cpp)

# Finals
add_executable(final
        src/final/src/entity/Category.cpp
        src/final/src/entity/Category.h
        src/final/src/entity/Subcategory.h
        src/final/src/entity/Subcategory.cpp
        src/final/src/entity/Record.cpp
        src/final/src/entity/Record.h
        src/final/src/entity/Date.cpp
        src/final/src/entity/Date.h
        src/final/src/main.cpp
        src/final/src/util/jest.h
        src/final/src/util/jest.cpp
        src/final/src/entity/entities.h
)