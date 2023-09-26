#include "settings.h"
#include <fstream>
#include <cstddef>

using std::byte;

/**
 * Creates a widget.
 * @param switches The combinations of switches of the widget
 */
byte createWidget(short switches) {
    // ?
    return (byte) switches;
}

/**
 * Checks whether a byte contains a specified switch.
 * @param byte The byte to check
 * @param _switch The switch to check
 */
bool validateSwitch(byte widget, Switch _switch) {
    return (widget & static_cast<byte>(_switch)) != byte{0};
}

/**
 * Prints a byte.
 * @param a The byte to print
 * @param os The output stream
 */
void printByte(byte a, std::ostream &os) {
//    os << static_cast<int>(a);
}

/**
 * Prints switches.
 * @param byte The byte to print switches
 * @param os The output stream
 */
void printSwitches(byte switches, std::ostream &os) {

}

/**
 * Prints widget options, and allows user to create their own widgets.
 */
byte printMenu() {
    byte res{0};

    return res;
}