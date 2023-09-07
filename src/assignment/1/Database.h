#ifndef ADVANCED_CPP_BHCC_DATABASE_H
#define ADVANCED_CPP_BHCC_DATABASE_H

#include "Student.h"

/**
 * Student records.
 * @author James Chan
 */
class Database {
private:
    Student[] studentList;
public:
    /**
     * Adds a student to the database.
     * @param student The student to add
     */
    void addStudent(Student student);

    /**
     * Drops a student from the database.
     */
    void dropStudent();

    /**
     * Grades a student.
     * @param student The student to grade
     * @param score The score
     */
    void gradeStudent(Student student, double score);

    void viewStudents();

    void viewCurrentStudents();

    void viewDroppedStudents();
};

#endif
