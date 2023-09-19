#ifndef ADVANCED_CPP_BHCC_CIRCLE_H
#define ADVANCED_CPP_BHCC_CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
public:
    Circle() : Shape(std::string_view("circle")) {}

    void playSound() override {
        std::cout << "Swing your partner round and round - Pitbull" << std::endl;
    }
};

#endif
