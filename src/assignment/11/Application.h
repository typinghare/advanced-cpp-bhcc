#ifndef ADVANCED_CPP_BHCC_APPLICATION_H
#define ADVANCED_CPP_BHCC_APPLICATION_H

#include <vector>

#include "Student.h"

/**
 * @brief Application stores students and outputs students after sorting.
 * @note I used `std::vector` to store students because I don't know how many students are there in
 * advanced when I instantiate. An advantage that `std::vector` is over array is that we don't have
 * to specify the number of elements when we create it. As a price, it consumes more memory
 * resources and time. However, I don't think it's a big deal.
 */
class Application {
private:
    std::vector<Student> studentVector;
public:
    /**
     * @brief Adds a student.
     * @param student The student to add
     */
    void addStudent(const Student &student);

    /**
     * @brief Outputs the order of applicants from the most qualified to the least qualified.
     */
    void outputStudents(std::ostream &os);
};

/**
 * @brief Prints a table in a better format.
 * @note It should be in another file, such as "util.h". I put it here because I don't want to
 * create extra files.
 * @param os The output stream.
 * @param header The header of the table.
 * @param records The records to print.
 */
void printTable(
    std::ostream &os,
    std::vector<std::string> &header,
    std::vector<std::vector<std::string>> &records
);

#endif
