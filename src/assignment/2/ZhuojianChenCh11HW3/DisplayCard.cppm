//export module storeshelf:displaycard;
//
//import <iostream>;
//
//export namespace StoreShelf {
//    class DisplayCard {
//    public:
//        DisplayCard() {
//            std::cout << "The constructor of DisplayCard class." << std::endl;
//        }
//    };
//}


#ifndef ADVANCED_CPP_BHCC_DISPLAYCARD_CPPM
#define ADVANCED_CPP_BHCC_DISPLAYCARD_CPPM

#include <iostream>

namespace StoreShelf {
    class DisplayCard {
    public:
        DisplayCard() {
            std::cout << "The constructor of DisplayCard class." << std::endl;
        }
    };
}

#endif