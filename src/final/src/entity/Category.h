#ifndef ADVANCED_CPP_BHCC_CATEGORY_H
#define ADVANCED_CPP_BHCC_CATEGORY_H

#include <iostream>

class Category {
private:
    unsigned int id;
    std::string_view name;
public:
    /**
     * Creates a category.
     * @param id The ID of this category.
     * @param name The name of this category.
     */
    Category(unsigned int id, std::string_view name);

    /**
     * Returns the ID of this category.
     * @return the ID of this category.
     */
    [[nodiscard]] unsigned int getId() const;

    /**
     * Returns the name of this category.
     * @return the name of this category.
     */
    std::string_view getName();
};

#endif
