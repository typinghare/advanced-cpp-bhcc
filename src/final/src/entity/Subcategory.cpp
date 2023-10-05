#include "Subcategory.h"


Subcategory::Subcategory(
    unsigned int id,
    std::string_view name,
    Category &category
) : id(id), name(name), category(category) {
}

unsigned int Subcategory::getId() const {
    return id;
}

std::string_view Subcategory::getName() {
    return name;
}

Category &Subcategory::getCategory() const {
    return category;
}