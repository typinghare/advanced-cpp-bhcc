#include "Category.h"


Category::Category(
    unsigned int id,
    std::string_view name
) : id(id), name(name) {
}

unsigned int Category::getId() const {
    return id;
}

std::string_view Category::getName() {
    return name;
}