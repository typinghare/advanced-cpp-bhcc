#include "StudentCourse.h"
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
 */
std::unique_ptr<StudentCourse> read(const std::string &path) {
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
    auto studentCourse = std::make_unique<StudentCourse>(line);
    Hashtable &courseHashtable = studentCourse->getCourseHashtable();

    // Continue to read the courses
    while (std::getline(inputFile, line)) {
        trim(line);
        std::vector<std::string> sp = splitStringWithSpace(line);

        // Skips the first two elements
        for (auto it = sp.begin() + 2; it != sp.end(); it++) {
            // The first three character is the key, the following number is the value
            std::string key = it->substr(0, 3), value = it->substr(3);
            std::vector<int> *numberVector = courseHashtable.setIfAbsent(key);
            numberVector->push_back(std::stoi(value));
        }
    }

    inputFile.close();

    return studentCourse;
}

/**
 * @brief Assignment 12_dated.
 * @reference https://en.wikipedia.org/wiki/Hash_table
 * @reference https://en.cppreference.com/w/cpp/filesystem/canonical
 * @reference https://stackoverflow.com/questions/1569726/difference-stdruntime-error-vs-stdexception
 * @reference https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 *
 * @note I've been struggling with the memory management. Sometimes I don't know whether to store
 * the variables (including the class member variables) on the stack or on the heap. I choose to
 * store on the heap to keep it save (so that the data will not suddenly disappear for no reason).
 * I asked ChatGPT the same question and it told me that just feel free to use smart pointers and I
 * don't have to manage the memory by myself. Finally in the `read()` method I leveraged unique
 * pointer and it worked fine.
 */
int main() {
    // Personal test (test files are under "../assets/assignment_12")
    // auto studentCourse1 = read("../assets/assignment_12/CSStudent_courses.txt");
    // auto studentCourse2 = read("../assets/assignment_12/CSStudent_courses1.txt");

    auto studentCourse1 = read("CSStudent_courses.txt");
    auto studentCourse2 = read("CSStudent_courses1.txt");

    studentCourse1->print(std::cout);
    std::cout << std::endl;
    studentCourse2->print(std::cout);

    return 0;
}