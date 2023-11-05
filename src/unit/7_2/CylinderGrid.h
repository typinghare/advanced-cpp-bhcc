#ifndef ADVANCED_CPP_BHCC_CylinderGridGRID_H
#define ADVANCED_CPP_BHCC_CylinderGridGRID_H

#include "Cylinder.h"

class CylinderGrid {
public:
    CylinderGrid(int nRows, int nCols);

    /**
     * @brief Destructor.
     */
    ~CylinderGrid();

    /**
     * @brief Copy constructor.
     * @param other Other CylinderGrid to copy.
     */
    CylinderGrid(const CylinderGrid &other);

    /**
     * @brief Move constructor.
     */
    CylinderGrid(CylinderGrid &&other) noexcept;

    /**
     * @brief Copy assignment operator.
     * @param other The other CylinderGrid to copy.
     * @return
     */
    CylinderGrid &operator=(const CylinderGrid &other);

    /**
     * @brief Move assignment operator.
     * @param other The other CylinderGrid to move.
     */
    CylinderGrid &operator=(CylinderGrid &&other) noexcept;

    /**
     * @brief Returns the cylinder at certain position.
     */
    Cylinder getCylinderAt(int row, int col);

private:
    int row;
    int col;
    Cylinder **data;
};

#endif
