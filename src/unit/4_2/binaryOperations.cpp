#include "settings.h"
#include <cstddef>

using std::byte;

const std::string switchStringArray[] = {
    "is plastic",
    "is recyclable",
    "is dishwasher safe",
    "is freezer safe",
    "is sugar free",
    "is gluten free",
    "is poisonous",
    "has lid"
};


byte createWidget(short switches) {
    return (byte) switches;
}

bool validateSwitch(byte _byte, Switch _switch) {
    return (_byte & (byte) (_switch)) != byte{0};
}

void printByte(byte _byte, std::ostream &os) {
    for (int i = 7; i >= 0; i--) {
        byte mask = (byte) 1 << i;
        os << ((_byte & mask) == mask ? 1 : 0);
    }
}

void printSwitches(byte switches, std::ostream &os) {
    os << "The widget ";
    for (int i = 0; i < 8; i++) {
        if (validateSwitch(switches, (Switch) (1 << i))) {
            os << switchStringArray[i] << "; ";
        }
    }
}

byte printMenu() {
    // Print widget options
    std::cout << std::endl << "The switches menus is as follows:" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << "[" << i << "] " << switchStringArray[i] << std::endl;
    }

    // Collect switches
    short switches = 0;
    while (true) {
        std::cout << "Enter a number (0-7), or finish creating by input -1: ";

        short m = 0;
        std::cin >> m;
        if (m == -1) {
            break;
        } else if (m >= 0 & m < 8) {
            switches |= 1 << m;
        } else {
            std::cout << "Invalid input: " << m << std::endl;
            continue;
        }
    }

    return createWidget(switches);
}

