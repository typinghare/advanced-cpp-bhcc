#ifndef ADVANCED_CPP_BHCC_SETTINGS_H
#define ADVANCED_CPP_BHCC_SETTINGS_H

#include <iostream>

enum class Switch : unsigned char {
    IS_PLASTIC = 0b0,
    IS_RECYCLABLE = 0b1,
    IS_DISHWASHER_SAFE = 0b10,
    IS_FREEZER_SAFE = 0b100,
    IS_SUGAR_FREE = 0b1000,
    IS_GLUTEN_FREE = 0b10000,
    IS_POISONOUS = 0b100000,
    HAS_LID = 0b1000000,
};

#endif

