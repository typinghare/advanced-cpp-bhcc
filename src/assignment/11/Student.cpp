#include "Student.h"

#include <utility>

Student::Student(std::string name, float gpa, int credits) :
    name(std::move(name)), gpa(gpa), credits(credits) {
}

std::string Student::getName() const {
    return name;
}

float Student::getGpa() const {
    return gpa;
}

int Student::getCredits() const {
    return credits;
}