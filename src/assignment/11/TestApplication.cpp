#include <cctype>
#include "Application.h"

void staticTest() {
    Application application;

    application.addStudent(Student("Sally", 3.3, 18));
    application.addStudent(Student("Hicham", 3.9, 15));
    application.addStudent(Student("lzzy", 3.9, 18));
    application.addStudent(Student("Joseph", 3.3, 18));
    application.addStudent(Student("Md", 3.5, 12));

    application.outputStudents(std::cout);
}

/**
 * @brief User input students' data.
 */
void dynamicTest() {
    Application application;

    // Input students
    std::cout << "[Input Students]" << std::endl;
    while (true) {
        std::string name;
        float gpa, credit;
        std::cout << "Please input the full name of the student: ";
        std::getline(std::cin, name);
        std::cout << "Please input the GPA of the student (0 ~ 4.0): ";
        std::cin >> gpa;
        std::cout << "Please input the credits of the student (0 ~ 30): ";
        std::cin >> credit;

        // Create and add the student to the application
        application.addStudent(Student(name, gpa, credit));

        // Ask the user if they want to add another user
        char answerOfContinue;
        std::cout << "Do you want to add another student? (y/n) ";
        std::cin >> answerOfContinue;
        std::cin.ignore();
        if (std::tolower(answerOfContinue) == 'n') {
            break;
        }
    }

    // Output students
    std::cout << std::endl << "[Output Students]" << std::endl;
    application.outputStudents(std::cout);
}

int main() {
    staticTest();
    std::cout << std::endl;
    dynamicTest();

    return 0;
}