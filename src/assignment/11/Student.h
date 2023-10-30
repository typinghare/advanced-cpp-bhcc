#ifndef ADVANCED_CPP_BHCC_STUDENT_H
#define ADVANCED_CPP_BHCC_STUDENT_H

#include <iostream>

class Student {
private:
    std::string name;
    float gpa;
    int credits;
public:
    /**
     * @brief Creates a student.
     * @param name The name of this student.
     * @param gpa The GPA of this student.
     * @param credit The number of credits this students has earned.
     */
    Student(std::string name, float gpa, int credits);

    /**
     * @brief Returns the name of this student.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Returns the GPA of this student.
     */
    [[nodiscard]] float getGpa() const;

    /**
    * @brief Returns the GPA of this student.
    */
    [[nodiscard]] int getCredits() const;

    /**
     * @brief Copy assignment operator.
     * @param student Other student to copy.
     */
    Student &operator=(const Student &student) {
        if (this != &student) {
            name = student.name;
            gpa = student.gpa;
            credits = student.credits;
        }

        return *this;
    }
};

#endif
