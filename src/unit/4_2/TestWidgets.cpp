//
//  TestWidgets.cpp
//  CSC284WB SP2023
//
//  Updated Liz Miller 1/15/2023.
//

#include <iostream>
#include <fstream>
#include <cstddef>
#include "settings.h"

using namespace std;

// The declarations of functions are moved to setting.h

int main() {
    /* create a widget with the following settings:
     IS_PLASTIC, IS_RECYCLABLE, IS_DISHWASHER_SAFE, IS_FREEZER_SAFE, IS_SUGAR_FREE, IS_GLUTEN_FREE, IS_POISONOUS, HAS_LID
     */
    short switches1 =
        (short) Switch::IS_PLASTIC |
        (short) Switch::IS_RECYCLABLE |
        (short) Switch::IS_DISHWASHER_SAFE |
        (short) Switch::IS_FREEZER_SAFE |
        (short) Switch::IS_SUGAR_FREE |
        (short) Switch::IS_GLUTEN_FREE |
        (short) Switch::IS_POISONOUS |
        (short) Switch::HAS_LID;
    byte widget1 = createWidget(switches1);
    cout << "Widget1: ";
    printByte(widget1, cout);
    cout << endl;
    printSwitches(widget1, cout);
    cout << endl;

    /* create a widget with the following settings:
     IS_SUGAR_FREE, IS_POISONOUS, IS_GLUTEN_FREE
     */
    short switches2 =
        (short) Switch::IS_SUGAR_FREE |
        (short) Switch::IS_POISONOUS |
        (short) Switch::IS_GLUTEN_FREE;
    byte widget2 = createWidget(switches2);
    cout << "Widget2: ";
    printByte(widget2, cout);
    cout << endl;
    printSwitches(widget2, cout);
    cout << endl;

    /* create a widget with the following settings:
     IS_PLASTIC, IS_RECYCLABLE, IS_DISHWASHER_SAFE, IS_POISONOUS, HAS_LID
     */
    short switches3 =
        (short) Switch::IS_PLASTIC |
        (short) Switch::IS_RECYCLABLE |
        (short) Switch::IS_DISHWASHER_SAFE |
        (short) Switch::IS_POISONOUS |
        (short) Switch::HAS_LID;
    byte widget3 = createWidget(switches3);
    cout << "Widget3: ";
    printByte(widget3, cout);
    cout << endl;
    printSwitches(widget3, cout);
    cout << endl;

    /**
     * Create a widget with printMenu() function
     */
    byte newWidget = printMenu();
    cout << "Here is your new widget: ";
    printByte(newWidget, cout);
    cout << endl;
    printSwitches(newWidget, cout);
    return 0;
}
