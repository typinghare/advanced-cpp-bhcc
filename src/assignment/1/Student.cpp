
#include "Student.h"

#include <utility>
#include <iomanip>

using namespace std;

Student::Student(
    int id,
    std::string fullName
) : mId(id), mFullName(std::move(fullName)), mGradePoint(0.0), mDropped(false) {
}

int Student::getId() const {
    return mId;
}

const std::string &Student::getFullName() const {
    return mFullName;
}

void Student::setFullName(const std::string &fullName) {
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