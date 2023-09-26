//
//  TestWidgets.cpp
//  CSC284WB SP2023
//
//  Updated Liz Miller 1/15/2023.
//

/**
 * @link https://docs.google.com/document/d/1qq-kLe49lYfQqvGHpK6XMu9Akf0jiNMLpNgJHcKhlaI
 */

#include <iostream>
#include "binaryOperations.cpp"

using namespace std;

int main() {

    /* create a widget with the following settings:
     IS_PLASTIC, IS_RECYCLABLE, IS_DISHWASHER_SAFE, IS_FREEZER_SAFE, IS_SUGAR_FREE, IS_GLUTEN_FREE, IS_POISONOUS, HAS_LID
     */
    short switches1 =
        static_cast<char>(Switch::IS_PLASTIC) &
        static_cast<char>(Switch::IS_RECYCLABLE) &
        static_cast<char>(Switch::IS_DISHWASHER_SAFE) &
        static_cast<char>(Switch::IS_FREEZER_SAFE) &
        static_cast<char>(Switch::IS_SUGAR_FREE) &
        static_cast<char>(Switch::IS_GLUTEN_FREE) &
        static_cast<char>(Switch::IS_POISONOUS) &
        static_cast<char>(Switch::HAS_LID);
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
        static_cast<char>(Switch::IS_SUGAR_FREE) &
        static_cast<char>(Switch::IS_GLUTEN_FREE) &
        static_cast<char>(Switch::IS_POISONOUS);
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
        static_cast<char>(Switch::IS_PLASTIC) &
        static_cast<char>(Switch::IS_RECYCLABLE) &
        static_cast<char>(Switch::IS_DISHWASHER_SAFE) &
        static_cast<char>(Switch::IS_POISONOUS) &
        static_cast<char>(Switch::HAS_LID);
    byte widget3 = createWidget(switches3);
    cout << "Widget3: ";
    printByte(widget3, cout);
    cout << endl;
    printSwitches(widget3, cout);
    cout << endl;
    byte newWidget = printMenu();
    cout << "Here is your new widget: ";
    printByte(newWidget, cout);
    cout << endl;
    printSwitches(newWidget, cout);

    return 0;
}
