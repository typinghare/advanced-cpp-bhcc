
#include "Student.h"

#include <utility>

Student::Student(std::string fullName) : mFullName(std::move(fullName)), mScore(0.0),
                                         mDropped(false) {
}

const std::string & Student::getFullName() const {
    return mFullName;
}

void Student::setFullName(const std::string &fullName) {
    mFullName = fullName;
}

double Student::getScore() const {
    return mScore;
}

void Student::setScore(double score) {
    mScore = score;
}

bool Student::isDropped() const {
    return mDropped;
}

void Student::drop() {
    mDropped = true;
}

void Student::reEntry() {
    mDropped = false;
}