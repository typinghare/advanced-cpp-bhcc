#ifndef ADVANCED_CPP_BHCC_TRIANGLE_H
#define ADVANCED_CPP_BHCC_TRIANGLE_H

#include <iostream>
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle() : Shape(std::string_view("triangle")) {}

    void playSound() override {
        std::cout << "Triangle man hates particle man - They Might Be Giants" << std::endl;
    }
};

#endif
