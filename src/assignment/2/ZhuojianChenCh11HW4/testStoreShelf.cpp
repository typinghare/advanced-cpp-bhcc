//import storeshelf;
#include "bookshelf.cppm"

int main() {
    StoreShelf::Item item;
    StoreShelf::DisplayCard displayCard;

    std::cout << item.spaceTaken(1.0) << std::endl;
    std::cout << displayCard.spaceTaken(10.0) << std::endl;
    // 0.393701
    // 3.93701

    return 0;
}