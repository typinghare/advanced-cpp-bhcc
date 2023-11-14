#include "Student.h"

Student::Student(std::string name) : name(std::move(name)) {
}

std::string Student::getName() const {
    return name;
}

HashTable &Student::getCourseHashTable() {
    return courseHashtable;
}

void Student::print(std::ostream &os) {
    os << name << std::endl;

    std::vector<std::string> keys = courseHashtable.keys();
    std::sort(keys.begin(), keys.end());

    for (const auto &key: keys) {
        os << key;
        std::set<int> *courseNumberSet = courseHashtable.get(key);

        // Move all elements in the set to a vector, and sort the vector
        std::vector<int> courseNumberVector(
            courseNumberSet->begin(),
            courseNumberSet->end()
        );
        std::sort(courseNumberVector.begin(), courseNumberVector.end());

        for (int courseNumber: courseNumberVector) {
            os << ' ' << courseNumber;
        }
        os << std::endl;
    }
}