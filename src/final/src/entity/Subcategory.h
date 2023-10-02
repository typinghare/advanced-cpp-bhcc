#ifndef ADVANCED_CPP_BHCC_SUBCATEGORY_H
#define ADVANCED_CPP_BHCC_SUBCATEGORY_H

#include <iostream>
#include "Category.h"

class Subcategory {
private:
    unsigned int id;
    std::string_view name;
    Category &category;
public:
    Subcategory(unsigned int id, std::string_view name, Category &category);

    [[nodiscard]] unsigned int getId() const;

    std::string_view getName();

    Category &getCategory();
};

#endif
