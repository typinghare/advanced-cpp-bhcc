
#include "Student.h"

#include <iomanip>

using namespace std;

Student::Student(
    int id,
    std::string_view &fullName
) : mId(id), mFullName(fullName), mGradePoint(0.0), mDropped(false) {
}

int Student::getId() const {
    return mId;
}

const std::string_view &Student::getFullName() const {
    return mFullName;
}

void Student::setFullName(const std::string_view &fullName) {
    mFullName = fullName;
}

double Student::getGradePoint() const {
    return mGradePoint;
}

void Student::setGradePoint(double gradePoint) {
    mGradePoint = gradePoint;
}

bool Student::isDropped() const {
    return mDropped;
}

void Student::drop() {
    mDropped = true;
}

void Student::display() const {
    cout << "[Student] "
         << "ID = " << getId() << "; "
         << "Fullname = " << getFullName() << "; "
         << "Grade Point = " << std::fixed << std::setprecision(2) << getGradePoint() << "; "
         << "Status = " << (isDropped() ? "DROPPED" : "CURRENT")
         << endl;
}