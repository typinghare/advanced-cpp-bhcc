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

void printByte(byte a, ostream& os);
void printSwitches(std::byte switches, ostream& os);
std::byte printMenu();

//you may change this prototype 

//byte createWidget(short value); // THERE IS ONLY ONE INPUT PARAMETER!!

int main() {
   
    /* create a widget with the following settings:
     IS_PLASTIC, IS_RECYCLABLE, IS_DISHWASHER_SAFE, IS_FREEZER_SAFE, IS_SUGAR_FREE, IS_GLUTEN_FREE, IS_POISONOUS, HAS_LID
     */
    byte widget1 = createWidget( /* input parameter here */);
    cout << "Widget1: ";
    printByte(widget1, cout);
    cout << endl;
    printSwitches(widget1, cout);
    cout << endl;
    /* create a widget with the following settings:
     IS_SUGAR_FREE, IS_POISONOUS, IS_GLUTEN_FREE
     */
    byte widget2 = createWidget( /* input parameter here */ );
    cout << "Widget2: ";
    printByte(widget2, cout);
    cout << endl;
    printSwitches(widget2, cout);
    cout << endl;
    /* create a widget with the following settings:
     IS_PLASTIC, IS_RECYCLABLE, IS_DISHWASHER_SAFE, IS_POISONOUS, HAS_LID
     */
    byte widget3 = createWidget( /* input parameter here */ );
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
