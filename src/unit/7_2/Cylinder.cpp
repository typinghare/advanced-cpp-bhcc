#include "Cylinder.h"
#include <sstream>
#include <iomanip>

std::string Cylinder::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2)
       << "Height=" << height << "; "
       << "Radius=" << radius;
    return ss.str();
}