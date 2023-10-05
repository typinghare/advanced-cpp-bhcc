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
    /**
     * Creates a record.
     * @param id The ID of this record.
     * @param date The creation date.
     * @param category The category this record belongs to.
     * @param subcategory The subcategory this record belongs to.
     * @param amount The amount of this record (in US dollars).
     */
    Record(
        unsigned int id,
        Date date,
        Category &category,
        Subcategory &subcategory,
        double amount
    );

    /**
     * Returns the ID of this record.
     * @return the ID of this record.
     */
    [[nodiscard]] unsigned int getId() const;

    /**
     * Returns the creation date.
     * @return the creation date.
     */
    [[nodiscard]] Date getDate() const;

    /**
     * Returns the category this record belongs to.
     * @return the category this record belongs to.
     */
    [[nodiscard]] Category & getCategory() const;

    /**
     * Returns the subcategory this record belongs to.
     * @return the subcategory this record belongs to.
     */
    [[nodiscard]] Subcategory &getSubcategory() const;

    /**
     * Returns the amount of this record.
     * @return the amount of this record.
     */
    [[nodiscard]] double getAmount() const;
};

#endif
