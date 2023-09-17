#include "Database.h"

Student &Database::addStudent(std::string_view &fullName) {
    size_t studentId = mStudentVector.size();
    Student student(static_cast<int>(studentId), fullName);
    mStudentVector.push_back(student);
    return mStudentVector.back();
}

void Database::dropStudent(int studentId) {
    Student &student = mStudentVector.at(studentId);
    student.drop();
}

void Database::gradeStudent(int studentId, double gradePoint) {
    Student &student = mStudentVector.at(studentId);
    student.setGradePoint(gradePoint);
}

void Database::viewStudents() {
    for (const Student &student: mStudentVector) {
        student.display();
    }
}

void Database::viewCurrentStudents() {
    for (const Student &student: mStudentVector) {
        if (!student.isDropped()) {
            student.display();
        }
    }
}

void Database::viewDroppedStudents() {
    for (const Student &student: mStudentVector) {
        if (student.isDropped()) {
            student.display();
        }
    }
}