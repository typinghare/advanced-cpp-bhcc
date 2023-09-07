#ifndef ADVANCED_CPP_BHCC_STUDENT_H
#define ADVANCED_CPP_BHCC_STUDENT_H

#include <iostream>

/**
 * This class maintains all the information about a student.
 * @author James Chan
 */
class Student {
public:
    /**
     * Creates a student.
     * @param fullName The full name of this student
     */
    explicit Student(std::string fullName);

    /**
     * Returns the full name of this student.
     * @return The full name
     */
    const std::string & getFullName() const;

    /**
     * Sets the student's fullname.
     * @param fullName The student's fullname
     */
    void setFullName(const std::string &fullName);

    /**
     * Returns the score of this student.
     * @return The score
     */
    double getScore() const;

    /**
     * Sets the score of this student.
     * @param score
     */
    void setScore(double score);

    /**
     * Whether this student is dropped.
     * @return true if this students has dropped; false otherwise
     */
    bool isDropped() const;

    /**
     * This student drops.
     */
    void drop();

    /**
     * This student re-entries, which will turn "mDropped" into false.
     */
    void reEntry();

private:
    std::string mFullName;
    double mScore;
    bool mDropped;
};

#endif
