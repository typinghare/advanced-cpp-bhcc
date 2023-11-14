#ifndef ADVANCED_CPP_BHCC_STUDENT_H
#define ADVANCED_CPP_BHCC_STUDENT_H

#include "HashTable.h"

/**
 * @brief Stores a student's name and their courses.
 */
class Student {
public:
    /**
     * @brief Creates a student course.
     * @param name The name of the student.
     */
    explicit Student(std::string name);

    /**
     * @brief Returns the name of the student.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Returns course hashtable.
     */
    HashTable &getCourseHashTable();

    /**
     * @brief Prints the student's name and their courses. The courses are printed in an alphabetic
     * order. The numbers of course are in ascending order.
     * @param os A output stream.
     */
    void print(std::ostream &os);

private:
    std::string name;
    HashTable courseHashtable;
};

#endif
