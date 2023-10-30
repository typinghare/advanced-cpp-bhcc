#include "Application.h"

#include <functional>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

void Application::addStudent(const Student &student) {
    studentVector.push_back(student);
}

/**
 * @note In the implementation, I chose to use `std::sort` to sort students because I don't want to
 * rebuild the wheel. I believe that the builtin `std::sort` performs much better than mine.
 */
void Application::outputStudents(std::ostream &os) {
    // Copy the student vector
    std::vector<Student> copiedStudentVector(studentVector);

    // Create a sort function; students are sorted in descending order by:
    // 1. GPA: If two students' GPAs are different, the one who has a higher GPA precedes
    // 2. Credits: If two students' credits are different, the one who has more credits precedes
    // 3. Name: If two students' names are different, sort them in ASCII order
    auto sortFunction = [](const Student &s1, const Student &s2) -> bool {
        if (s1.getGpa() != s2.getGpa()) {
            return s1.getGpa() > s2.getGpa();
        }

        if (s1.getCredits() != s2.getCredits()) {
            return s1.getCredits() > s2.getCredits();
        }

        return s1.getName() > s2.getName();
    };

    // Sort the vector with std::sort
    std::sort(copiedStudentVector.begin(), copiedStudentVector.end(), sortFunction);

    // Output in a form of table
    std::vector<std::string> header{"Name", "GPA", "Credits"};
    std::vector<std::vector<std::string>> records;
    for (const Student &student: copiedStudentVector) {
        std::stringstream _os;
        _os << std::fixed << std::setprecision(1) << student.getGpa();
        std::vector<std::string> record = {
            student.getName(),
            _os.str(),
            std::to_string(student.getCredits())
        };
        records.push_back(record);
    }

    printTable(os, header, records);
}

/**
 * @brief Fills following spaces to a string.
 * @param str The string to fill with following spaces.
 * @param length The length of the returned string.
 * @return
 */
std::string fillFollowingSpaces(const std::string &str, int length) {
    return str + std::string(length - str.length(), ' ');
}

void printTable(
    std::ostream &os,
    std::vector<std::string> &header,
    std::vector<std::vector<std::string>> &records
) {
    const int numCol = header.size();
    int colMaxLength[numCol];
    for (int i = 0; i < numCol; i++) {
        colMaxLength[i] = header[i].length();
    }

    for (std::vector<std::string> record: records) {
        for (int i = 0; i < numCol; i++) {
            colMaxLength[i] = std::max(colMaxLength[i], (int) record[i].length());
        }
    }

    int dividerLength = 0;
    for (int i = 0; i < numCol; i++) {
        colMaxLength[i] += 1;
        dividerLength += colMaxLength[i];
    }

    std::string divider(dividerLength + numCol + 1, '=');

    // Print the header
    os << divider << std::endl;
    for (int i = 0; i < numCol; i++) {
        os << '|' << fillFollowingSpaces(header[i], colMaxLength[i]);
    }
    os << '|' << std::endl << divider << std::endl;

    // Print the records
    for (const std::vector<std::string> &record: records) {
        for (int i = 0; i < numCol; i++) {
            os << '|' << fillFollowingSpaces(record[i], colMaxLength[i]);
        }
        os << '|' << std::endl;
    }
    os << divider << std::endl;
}