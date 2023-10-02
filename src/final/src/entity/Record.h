#ifndef ADVANCED_CPP_BHCC_RECORD_H
#define ADVANCED_CPP_BHCC_RECORD_H

#include "Date.h"
#include "Category.h"
#include "Subcategory.h"

class Record {
private:
    unsigned int id;
    Date date;
    Category &category;
    Subcategory &subcategory;
    double amount;
public:
    Record(
        unsigned int id,
        Date date,
        Category &category,
        Subcategory &subcategory,
        double amount
    );

    [[nodiscard]] unsigned int getId() const;

    Date getDate();

    std::string_view getName();

    Category &getCategory();

    Subcategory &getSubcategory();

    [[nodiscard]] double getAmount() const;
};

#endif
