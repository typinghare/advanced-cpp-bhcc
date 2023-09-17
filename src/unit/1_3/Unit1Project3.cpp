/**
 * @note Requirements of Unit 1 Project 3.
 * Create a program that shows off the advantages of using strongly typed enumerators. Your program
 * should have at least two strongly typed enumerators, one value in the enumerations should have the
 * same name. You should have a function that takes the enumerator as an input parameter, and
 * another function that takes a cast value of the enumerator as an input value (e.g.
 * static_cast<int>(MY_ENUM::value) ). NOTE: the integer cast here is just an example.
 */

#include <iostream>

// Strongly typed enumeration for fruits
enum class Fruit {
    APPLE, BANANA, TOMATO, PEAR, AVOCADO
};

// Strongly typed enumeration for vegetables
enum class Vegetable {
    BROCCOLI, CELERY, TOMATO, ONION, LETTUCE
};

void printName(Fruit fruit);

void printName(Vegetable vegetable);

void printName(int fruit_or_vegetable);

int main() {
    // Initialize a fruit and a vegetable
    Fruit myFruit{Fruit::PEAR};
    Vegetable myVegetable{Vegetable::LETTUCE};

    // Good practices: Passing strongly typed enumerations to the printName function, so that the
    // compiler can decide which function to call with overload
    printName(myFruit);
    printName(myVegetable);

    // Bad practices: Passing integer to the printName function, compiler cannot decide whether it
    // represents a fruit or vegetable.
    printName(1);
    printName(static_cast<int>(Fruit::TOMATO));
    printName(static_cast<int>(Vegetable::TOMATO));

    return 0;
}

/**
 * Prints the name of a fruit.
 */
void printName(Fruit fruit) {
    switch (static_cast<Fruit>(fruit)) {
        case Fruit::APPLE:
            std::cout << "Fruit apple" << std::endl;
            break;
        case Fruit::BANANA:
            std::cout << "Fruit banana" << std::endl;
            break;
        case Fruit::TOMATO:
            std::cout << "Fruit tomato" << std::endl;
            break;
        case Fruit::PEAR:
            std::cout << "Fruit pear" << std::endl;
            break;
        case Fruit::AVOCADO:
            std::cout << "Fruit avocado" << std::endl;
            break;
    }
}

/**
 * Prints the name of a vegetable.
 */
void printName(Vegetable vegetable) {
    switch (static_cast<Vegetable>(vegetable)) {
        case Vegetable::BROCCOLI:
            std::cout << "Vegetable broccoli" << std::endl;
            break;
        case Vegetable::CELERY:
            std::cout << "Vegetable celery" << std::endl;
            break;
        case Vegetable::TOMATO:
            std::cout << "Vegetable tomato" << std::endl;
            break;
        case Vegetable::ONION:
            std::cout << "Vegetable onion" << std::endl;
            break;
        case Vegetable::LETTUCE:
            std::cout << "Vegetable lettuce" << std::endl;
            break;
    }
}

/**
 * Prints the name of a fruit or a vegetable.
 */
void printName(int fruit_or_vegetable) {
    if (fruit_or_vegetable == 0) {
        std::cout << "Fruit apple or Vegetable broccoli" << std::endl;
    } else if (fruit_or_vegetable == 1) {
        std::cout << "Fruit banana or Vegetable celery" << std::endl;
    } else if (fruit_or_vegetable == 2) {
        std::cout << "tomato, but can be either Fruit or Vegetable" << std::endl;
    } else if (fruit_or_vegetable == 3) {
        std::cout << "Fruit pear or Vegetable onion" << std::endl;
    } else if (fruit_or_vegetable == 4) {
        std::cout << "Fruit avocado or Vegetable lettuce" << std::endl;
    } else {
        std::cout << "Invalid index: " << fruit_or_vegetable << std::endl;
    }
}