//export module storeshelf:item;
//
//import <iostream>;
//
//export namespace StoreShelf {
//    class Item {
//    public:
//        Item() {
//            std::cout << "The constructor of Item class." << std::endl;
//        }
//    };
//}

#ifndef ADVANCED_CPP_BHCC_ITEM_CPPM
#define ADVANCED_CPP_BHCC_ITEM_CPPM

#include <iostream>

namespace StoreShelf {
    class Item {
    public:
        Item() {
            std::cout << "The constructor of Item class." << std::endl;
        }
    };
}

#endif