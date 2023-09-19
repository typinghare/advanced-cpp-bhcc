//export module bookshelf;

//import <iostream>;

//export namespace StoreShelf {
//    class Item {
//    public:
//        Item() {
//            std::cout << "The constructor of Item class." << std::endl;
//        }
//    };
//
//    class DisplayCard {
//    public:
//        DisplayCard() {
//            std::cout << "The constructor of DisplayCard class." << std::endl;
//        }
//    };
//}


#include <iostream>

namespace StoreShelf {
    class Item {
    public:
        Item() {
            std::cout << "The constructor of Item class." << std::endl;
        }
    };

    class DisplayCard {
    public:
        DisplayCard() {
            std::cout << "The constructor of DisplayCard class." << std::endl;
        }
    };
}