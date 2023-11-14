#include "Student.h"
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <memory>

/**
 * @brief Splits a string with space character.
 * @param str The string to split.
 */
std::vector<std::string> splitStringWithSpace(const std::string &str) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

/**
 * Trims leading and trailing spaces from a string.
 * @param str The string to trim.
 * @param whitespace Whitespace characters.
 * @return A trimmed string.
 */
void trim(std::string &str, const std::string &whitespace = " \t\r") {
    str.erase(0, str.find_first_not_of(whitespace));
    str.erase(str.find_last_not_of(whitespace) + 1);
}

/**
 * @brief Reads a text file and returns a StudentCourse instance.
 * @param path The path of the file.
 * @return A student wrapped by a unique pointer.
 */
std::shared_ptr<Student> read(const std::string &path) {
    std::string absolutePath = std::filesystem::canonical(std::filesystem::absolute(path));
    std::ifstream inputFile(absolutePath);

    if (!std::filesystem::exists(absolutePath)) {
        throw std::runtime_error("File does not exist: " + absolutePath);
    }

    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open the file: " + absolutePath);
    }

    std::string line;
    std::getline(inputFile, line);  // The first line is the student's name
    trim(line);

    // Create a student course
    auto student = std::make_shared<Student>(line);
    HashTable &courseHashtable = student->getCourseHashTable();

    // Continue to read the courses
    while (std::getline(inputFile, line)) {
        trim(line);
        std::vector<std::string> sp = splitStringWithSpace(line);

        // Skips the first two elements
        for (auto it = sp.begin() + 2; it != sp.end(); it++) {
            // The first three character is the key, the following number is the value
            std::string key = it->substr(0, 3), value = it->substr(3);
            std::set<int> *courseNumberSet = courseHashtable.setIfAbsent(key);
            courseNumberSet->insert(std::stoi(value));
        }
    }

    inputFile.close();

    return student;
}

/**
 * @brief Write the information of a group of students.
 * @param path The path of the output file.
 * @param studentVector The students to output.
 */
void write(const std::string &path, const std::vector<std::shared_ptr<Student>> &studentVector) {
    std::string absolutePath = std::filesystem::absolute(path);
    std::ofstream outputFile(absolutePath);

    for (const auto &student: studentVector) {
        student->print(outputFile);
        outputFile << std::endl;
    }

    outputFile.close();
}

/**
 * @brief Assignment 12_dated.
 * @reference https://www.geeksforgeeks.org/set-in-cpp-stl/
 * @reference https://en.wikipedia.org/wiki/Hash_table
 * @reference https://en.cppreference.com/w/cpp/filesystem/canonical
 * @reference https://stackoverflow.com/questions/1569726/difference-stdruntime-error-vs-stdexception
 * @reference https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 *
 * @note I've been struggling with the memory management. Sometimes I don't know whether to store
 * the variables (including the class member variables) on the stack or on the heap. I choose to
 * store on the heap to keep it save (so that the data will not suddenly disappear for no reason).
 * I asked ChatGPT the same question and it told me that just feel free to use smart pointers and I
 * don't have to manage the memory by myself. Finally in the `read()` method I leveraged the share
 * pointer and it worked fine.
 */
int main() {
    // [MY TEST] (test files are under "../assets/assignment_12")
    auto student1 = read("../assets/assignment_12/CSStudent_courses.txt");
    auto student2 = read("../assets/assignment_12/CSStudent_courses1.txt");
    std::string outputPath = "../assets/assignment_12/output.txt";

    // [PROFESSOR TEST]
//    std::unique_ptr<Student> student1 = read("CSStudent_courses.txt");
//    std::unique_ptr<Student> student2 = read("CSStudent_courses1.txt");

    // Write to a file
    std::vector<std::shared_ptr<Student>> studentVector;
    studentVector.push_back(student1);
    studentVector.push_back(student2);
    write(outputPath, studentVector);

    return 0;
}