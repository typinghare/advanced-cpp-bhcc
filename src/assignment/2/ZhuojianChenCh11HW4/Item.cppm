//export module storeshelf:item;
//
//import <iostream>;
//import :internals;
//
//export namespace StoreShelf {
//    class Item {
//    public:
//        Item() {
//            std::cout << "The constructor of Item class." << std::endl;
//        }
//
//        double spaceTaken(double cm) { return StoreShelf::convertCmToIn(cm); }
//    };
//}

#ifndef ADVANCED_CPP_BHCC_ITEM_CPPM
#define ADVANCED_CPP_BHCC_ITEM_CPPM

#include <iostream>
#include "Internals.cppm"

namespace StoreShelf {
    class Item {
    public:
        Item() {
            std::cout << "The constructor of Item class." << std::endl;
        }

        double spaceTaken(double cm) { return StoreShelf::convertCmToIn(cm); }
    };
}

#endif