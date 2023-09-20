enum class Direction : char {
    UP, RIGHT, DOWN, LEFT
};

Direction changeDirection(Direction direction, char (*func)(char)) {
    return static_cast<Direction>(func(static_cast<char>(direction)));
}

char clockwise(char dir) {
    return (dir + 1) % 4;
}

char turnAround(char dir) {
    // How to simplify this function by applying bitwise operation techniques?
    if (dir == 0) return 2;
    if (dir == 1) return 3;
    if (dir == 2) return 0;
    if (dir == 3) return 1;

    return 0;
}

// Prints the string of the given direction
void printDirection(Direction direction) {
    // Implementation ...
}

int main() {
    printDirection(changeDirection(Direction::LEFT, clockwise));    // "Up"
    printDirection(changeDirection(Direction::DOWN, turnAround));   // "Up"
    printDirection(changeDirection(Direction::RIGHT, turnAround));  // "Left"
}

