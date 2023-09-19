#ifndef ADVANCED_CPP_BHCC_SQUARE_H
#define ADVANCED_CPP_BHCC_SQUARE_H

#include <iostream>
#include "Shape.h"

class Square : public Shape {
public:
    Square() : Shape("square") {
    }

    void playSound() override {
        std::cout << "Square or round, rich or poor\n"
                     "At the end of day and night all we want is more - Janelle Monae" << std::endl;
    }
};

#endif
