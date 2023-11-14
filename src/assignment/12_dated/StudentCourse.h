#ifndef ADVANCED_CPP_BHCC_STUDENTCOURSE_H
#define ADVANCED_CPP_BHCC_STUDENTCOURSE_H

#include <iostream>
#include "Hashtable.h"

/**
 * @brief Stores a student's name and their courses.
 */
class StudentCourse {
public:
    /**
     * @brief Creates a student course.
     * @param name The name of the student.
     */
    explicit StudentCourse(std::string name);

    /**
     * @brief Returns the name of the student.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Returns course hashtable.
     */
    Hashtable& getCourseHashtable();

    /**
     * Prints the student's name and their courses.
     * @param os A specific output stream.
     */
    void print(std::ostream &os);

private:
    std::string name;
    Hashtable courseHashtable;
};

#endif
