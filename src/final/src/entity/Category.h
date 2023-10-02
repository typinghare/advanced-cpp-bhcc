#ifndef ADVANCED_CPP_BHCC_CATEGORY_H
#define ADVANCED_CPP_BHCC_CATEGORY_H

#include <iostream>

class Category {
private:
    unsigned int id;
    std::string_view name;
public:
    Category(unsigned int id, std::string_view name);

    [[nodiscard]] unsigned int getId() const;

    std::string_view getName();
};

#endif
