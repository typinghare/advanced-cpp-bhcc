/**
 * @note These are just some self-use learning materials.
 *
 * @section Assignment Initialization versus Uniform Initialization
 * [Assignment Initialization] int a = 1;
 * [Uniform Initialization] int a{ 1 };
 * The assignment initialization is the traditional way of initializing a variable in C++, while the
 * uniform initialization is the modern initialization syntax introduced in C++. The latter is
 * considered more consistent and is recommended for most cases because:
 * (1) It provides better type safety and
 * (2) prevents narrowing conversions.
 *
 * @section Private Member Variables (Naming Conventions)
 * The practice of prefixing private member variables with an "m" or some other distinguishing
 * character is a common naming convention in C++ codebases. Here, "m" refers to "member".
 *
 * @section About Vector's Size
 * (1) Get the size of a vector: `size_t sizeOfVector = vector.size();`
 * (2) Convert it into int (or long): `int size = static_cast<int>(sizeOfVector);`
 *
 * @section About [[nodiscard]]
 * I ran into a weird warning saying that "Clang-Tidy: Function 'getId' should be marked
 * [[nodiscard]]", what was that? According to ChatGPT, The [[nodiscard]] attribute is a C++17
 * feature that helps catch situations where the return value of a function is unused, which can
 * be a potential source of bugs or unintended behavior in your code.
 *
 * @section Retrieving Elements from Vectors
 * The following version does not work properly because the "student" is a copy of the original
 * student object:
 *
 *     Student student = students.at(studentId);
 *
 * In order to modify the original object, use "&" to specify:
 *
 *     Student &student = students.at(studentId);
 *
 * To summarize, in C++, when you need to modify an object stored in a container like a vector, you
 * should use a reference to that object (like in the second version) rather than creating a copy
 * (like in the first version). Using a reference allows you to work directly with the object stored
 * in the container and make modifications to it.
 */

/**
 * @note This is the requirement of the reading assignment 1.
 *
 * Create a system similar to the Employee Records system in the textbook, however, this is a
 * Student Records system.
 * 1. Add a student - use string_views where appropriate!
 * 2. Drop a student.
 * 3. Grade a student.
 * 4. View all students, past and present.
 * 5. View all current students.
 * 6. View all dropped students.
 *
 * The default for a student's starting grade is either 0 or 4, depending on your philosophy.
 */

#include "Student.h"
#include "Database.h"

using namespace std;

/**
 * Testing student records database.
 * @Date Sep 7, 2023
 * @author James Chan
 * @environment MacOS 13.4; C++ 20; GNU Make 3.81
 */
int main() {
    // Create a database
    Database database;

    // Create a bunch of names
    vector<string> nameVector{
        "James Chan",
        "Patrick Andrews",
        "William Conway",
        "John Huynh",
        "Eric Souza"
    };

    // Add students to the database
    for (const string &name: nameVector) {
        database.addStudent(const_cast<string &>(name));
    }

    // Grade all students
    database.gradeStudent(0, 3.0);
    database.gradeStudent(1, 4.0);
    database.gradeStudent(2, 3.8);
    database.gradeStudent(3, 3.8);
    database.gradeStudent(4, 3.5);

    // Drops some students
    database.dropStudent(1);
    database.dropStudent(3);

    // View all students
    cout << "All students in the database: " << endl;
    database.viewStudents();
    cout << endl;

    // View all current students
    cout << "All current students in the database: " << endl;
    database.viewCurrentStudents();
    cout << endl;

    // View dropped students
    cout << "All dropped students in the database: " << endl;
    database.viewDroppedStudents();
    cout << endl;

    return 0;
}