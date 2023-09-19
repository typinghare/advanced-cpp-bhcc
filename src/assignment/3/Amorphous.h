#ifndef ADVANCED_CPP_BHCC_AMORPHOUS_H
#define ADVANCED_CPP_BHCC_AMORPHOUS_H

#include <iostream>
#include "Shape.h"

class Amorphous : public Shape {
public:
    Amorphous() : Shape(std::string_view("amorphous")) {}

    void playSound() override {
        playSound(std::string_view("Is this the real life?\n"
                                   "Is this just fantasy? - Queen"));
    }

    void playSound(std::string_view sound) {
        std::cout << sound << std::endl;
    }
};

#endif
