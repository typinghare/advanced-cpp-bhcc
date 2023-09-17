#ifndef ADVANCED_CPP_BHCC_STUDENT_H
#define ADVANCED_CPP_BHCC_STUDENT_H

#include <iostream>

/**
 * This class maintains all the information about a student.
 * Note that the default value "grade point" is 0.
 * @author James Chan
 */
class Student {
public:
    /**
     * Creates a student.
     * @param id The ID of this student
     * @param fullName The full name of this student
     */
    Student(int id, std::string_view &fullName);

    /**
     * Returns the ID of this student.
     * @return the ID of this student.
     */
    [[nodiscard]] int getId() const;

    /**
     * Returns the full name of this student.
     * @return the full name of this student.
     */
    [[nodiscard]] const std::string_view &getFullName() const;

    /**
     * Sets the student's fullname.
     * @param fullName The student's fullname
     */
    void setFullName(const std::string_view &fullName);

    /**
     * Returns the grade point of this student.
     * @return the grade point of this student.
     */
    [[nodiscard]] double getGradePoint() const;

    /**
     * Sets the grade point of this student.
     * @param gradePoint The grade point to set
     */
    void setGradePoint(double gradePoint);

    /**
     * Whether this student has dropped.
     * @return true if this students has dropped; false otherwise
     */
    [[nodiscard]] bool isDropped() const;

    /**
     * This student drops.
     */
    void drop();

    /**
     * Outputs this student info to console.
     */
    void display() const;

private:
    int mId;
    std::string_view mFullName;
    double mGradePoint;
    bool mDropped;
};

#endif
