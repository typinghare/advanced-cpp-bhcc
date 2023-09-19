//export module storeshelf:displaycard;
//
//import <iostream>;
//import :internals;
//
//export namespace StoreShelf {
//    class DisplayCard {
//    public:
//        DisplayCard() {
//            std::cout << "The constructor of DisplayCard class." << std::endl;
//        }
//
//        double spaceTaken(double cm) { return StoreShelf::convertCmToIn(cm); }
//    };
//}


#ifndef ADVANCED_CPP_BHCC_DISPLAYCARD_CPPM
#define ADVANCED_CPP_BHCC_DISPLAYCARD_CPPM

#include <iostream>
#include "Internals.cppm"

namespace StoreShelf {
    class DisplayCard {
    public:
        DisplayCard() {
            std::cout << "The constructor of DisplayCard class." << std::endl;
        }

        double spaceTaken(double cm) { return StoreShelf::convertCmToIn(cm); }
    };
}

#endif