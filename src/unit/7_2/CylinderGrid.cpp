#include "CylinderGrid.h"
#include "Cylinder.h"

CylinderGrid::CylinderGrid(int nRows, int nCols) : row(nRows), col(nCols) {
    data = new Cylinder *[row];
    for (int i = 0; i < row; ++i) {
        data[i] = new Cylinder[col];
        Cylinder cylinder = data[i][1];
        std::cout << cylinder.toString() << std::endl;
    }
}

CylinderGrid::~CylinderGrid() {
    delete data;
}

CylinderGrid::CylinderGrid(const CylinderGrid &other) : row(other.row), col(other.col) {
    std::cout << "[Copy Constructor]" << std::endl;
    data = new Cylinder *[row];
    for (int i = 0; i < row; i++) {
        data[i] = new Cylinder[col];
        for (int j = 0; j < col; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

CylinderGrid::CylinderGrid(CylinderGrid &&other) noexcept:
    row(other.row), col(other.col), data(other.data) {
    std::cout << "[Move Constructor]" << std::endl;
    other.row = 0;
    other.col = 0;
    other.data = nullptr;
}

CylinderGrid &CylinderGrid::operator=(const CylinderGrid &other) {
    std::cout << "[Copy Assignment]" << std::endl;
    if (this != &other) {
        row = other.row;
        col = other.col;
        data = new Cylinder *[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new Cylinder[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    return *this;
}

CylinderGrid &CylinderGrid::operator=(CylinderGrid &&other) noexcept {
    std::cout << "[Move Assignment]" << std::endl;
    if (this != &other) {
        row = other.row;
        col = other.col;
        data = other.data;
    }

    return *this;
}

Cylinder CylinderGrid::getCylinderAt(int row, int col) {
    return data[row][col];
}

