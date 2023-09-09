#ifndef ADVANCED_CPP_BHCC_DATABASE_H
#define ADVANCED_CPP_BHCC_DATABASE_H

#include "Student.h"
#include <vector>

/**
 * Student records database.
 * @author James Chan
 */
class Database {
public:
    /**
     * Adds a student to the database.
     * @param student The student to add
     * @return the student added
     */
    Student &addStudent(std::string &fullName);

    /**
     * Drops a student from the database.
     * @param studentId The ID of the student to drop
     */
    void dropStudent(int studentId);

    /**
     * Grades a student.
     * @param student The student to grade
     * @param score The score
     */
    void gradeStudent(int studentId, double score);

    /**
     * Prints all students on the console.
     */
    void viewStudents();

    /**
     * Prints all students who are not dropped on the console.
     */
    void viewCurrentStudents();

    /**
     * Prints all dropped students on the console.
     */
    void viewDroppedStudents();

private:
    /**
     * A vector to store all students.
     */
    std::vector<Student> mStudentVector;
};

#endif
