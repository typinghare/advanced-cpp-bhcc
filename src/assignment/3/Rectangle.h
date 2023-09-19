#ifndef ADVANCED_CPP_BHCC_RECTANGLE_H
#define ADVANCED_CPP_BHCC_RECTANGLE_H

#include <iostream>
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle() : Shape(std::string_view("rectangle")) {}

    void playSound() override {
        std::cout << "All in all it's just bricks in the wall - Pink Floyd" << std::endl;
    }
};

#endif
