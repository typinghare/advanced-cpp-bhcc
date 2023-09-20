#include <iostream>

enum class Direction : char {
    UP, RIGHT, DOWN, LEFT
};

Direction changeDirection(Direction direction, char (*func)(char)) {
    return static_cast<Direction>(func(static_cast<char>(direction)));
}

char clockwise(char dir) {
    return (dir + 1) % 4;   // Easy to implement
}

char turnAround(char dir) {
    // How to simplify this function applying bitwise techniques?
//    if (dir == 0) return 2;
//    if (dir == 1) return 3;
//    if (dir == 2) return 0;
//    if (dir == 3) return 1;
//
//    return 0;

    return dir ^ 2;
}

void printDirection(Direction direction) {
    switch (direction) {
        case Direction::UP:
            std::cout << "Up" << std::endl;
            break;
        case Direction::RIGHT:
            std::cout << "Right" << std::endl;
            break;
        case Direction::DOWN:
            std::cout << "Down" << std::endl;
            break;
        case Direction::LEFT:
            std::cout << "Left" << std::endl;
            break;
    }
}

int main() {
    // Tests; printDirection() prints the string of the given direction
    printDirection(changeDirection(Direction::LEFT, clockwise));    // "Up"
    printDirection(changeDirection(Direction::DOWN, turnAround));   // "Up"
    printDirection(changeDirection(Direction::RIGHT, turnAround));  // "Left"

    return 0;
}