#ifndef ADVANCED_CPP_BHCC_SETTINGS_H
#define ADVANCED_CPP_BHCC_SETTINGS_H

#include <iostream>

/**
 * @brief A strongly typed enumerator for the switches.
 */
enum class Switch : unsigned char {
    IS_PLASTIC = 0b1,
    IS_RECYCLABLE = 0b10,
    IS_DISHWASHER_SAFE = 0b100,
    IS_FREEZER_SAFE = 0b1000,
    IS_SUGAR_FREE = 0b10000,
    IS_GLUTEN_FREE = 0b100000,
    IS_POISONOUS = 0b1000000,
    HAS_LID = 0b10000000,
};

/**
 * @brief An array of description for corresponding switches.
 */
extern const std::string switchStringArray[];

/**
 * Creates a widget.
 * @param switches The combinations of switches of the widget
 * @return A widget (byte).
 */
std::byte createWidget(short switches);

/**
 * Validate a byte against a particular switch.
 * @param _byte The byte to validate.
 * @param _switch The specified switch to validate.
 */
bool validateSwitch(std::byte _byte, Switch _switch);

/**
 * Prints a byte.
 * @param _byte The byte to print.
 * @param os The output stream.
 */
void printByte(std::byte a, std::ostream &os);

/**
 * Prints switches.
 * @param byte The byte to print switches.
 * @param os The output stream.
 */
void printSwitches(std::byte switches, std::ostream &os);

/**
 * Prints the widget options, and allows the user to create their own widgets.
 * @return a byte value that is the widget.
 */
std::byte printMenu();

#endif