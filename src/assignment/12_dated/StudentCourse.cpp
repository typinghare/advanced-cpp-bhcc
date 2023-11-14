#include "StudentCourse.h"

#include <utility>

StudentCourse::StudentCourse(std::string name) : name(std::move(name)) {
}

std::string StudentCourse::getName() const {
    return name;
}

Hashtable& StudentCourse::getCourseHashtable() {
    return courseHashtable;
}


void StudentCourse::print(std::ostream &os) {
    os << name << std::endl;

    for (const auto &key: courseHashtable.keys()) {
        os << key;
        std::vector<int> *intVector = courseHashtable.get(key);
        for (int num: *intVector) {
            os << ' ' << num;
        }
        os << std::endl;
    }
}