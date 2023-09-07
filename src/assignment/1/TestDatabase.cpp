/**
 * @note This is just some study notes.
 *
 * 1. Assignment Initialization versus Uniform Initialization
 * [Assignment Initialization] int a = 1;
 * [Uniform Initialization] int a{ 1 };
 * The assignment initialization is the traditional way of initializing a variable in C++, while the
 * uniform initialization is the modern initialization syntax introduced in C++. The latter is
 * considered more consistent and is recommended for most cases because:
 * (1) It provides better type safety and
 * (2) prevents narrowing conversions.
 *
 * 2. Private Member Variables
 * The practice of prefixing private member variables with an "m" or some other distinguishing
 * character is a common naming convention in C++ codebases. Here, "m" refers to "member".
 */

/**
 * @note This is the requirement of reading assignment 1.
 * Create a system similar to the Employee Records system in the textbook, however, this is a
 * Student Records system.
 * 1. Add a student - use string_views where appropriate!
 * 2. Drop a student.
 * 3. Grade a student.
 * 4. View all students, past and present.
 * 5. View all current students.
 * 6. View all dropped students.
 */

#include <iostream>
#include "Student.h"

using namespace std;

void foo() {
    cout << __func__ << endl;
}

int main() {
    foo();

    Student student("");

    return 0;
}