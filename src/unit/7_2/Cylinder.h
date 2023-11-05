#ifndef ADVANCED_CPP_BHCC_CYLINDER_H
#define ADVANCED_CPP_BHCC_CYLINDER_H

#include <iostream>

class Cylinder {
public:
    /**
     * @brief Returns the radius and height of this cylinder.
     */
    [[nodiscard]] std::string toString() const;

private:
    double radius = 1.0;
    double height = 2.0;
};

#endif