/**
 * @note requirements for the reading assignment 3.
 * Convert the attached file to appropriate class or classes instead of enums. Add another class
 * "Amorphous" that also can rotate, and "play a sound", but the sound it plays must be passed in
 * as a string_view rather than be hard-coded for the shape as it currently is. In addition, add
 * a "color" field to all classes. The "colors" should be chosen from a strongly typed enumerator.
 * Be sure to implement proper style and naming conventions, as well as abstraction and code reuse
 * principles.
 *
 * Don't forget to refactor the main() function into a TestShapes.cpp file to test your new classes.
 */

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Amorphous.h"

/**
 * Converts a color into a string.
 */
std::string translateColor(Color color) {
    switch (color) {
        case Color::RED:
            return "red";
        case Color::GREEN:
            return "green";
        case Color::BLUE:
            return "blue";
    }
}

/**
 * Test all shapes.
 */
int main() {
    // Create an array of shapes
    const int NUM_SHAPE = 5;
    Shape *shapeArray[NUM_SHAPE];
    shapeArray[0] = new Circle();
    shapeArray[1] = new Rectangle();
    shapeArray[2] = new Square();
    shapeArray[3] = new Triangle();
    shapeArray[4] = new Amorphous();

    // Change the colors of some shapes
    shapeArray[1]->setColor(Color::BLUE);
    shapeArray[3]->setColor(Color::BLUE);
    shapeArray[4]->setColor(Color::GREEN);

    int shapeIndex = 0;
    do {
        // Print all shapes
        for (int i = 0; i < NUM_SHAPE; i++) {
            Shape *shape = shapeArray[i];
            std::cout << "[" << i + 1 << "] " << shape->getName() << std::endl;
        }

        std::cout << "Choose a shape, or 0 to quit: ";
        std::cin >> shapeIndex;

        if (shapeIndex == 0) {
            std::cout << "\nBye." << std::endl;
            break;
        }

        if (shapeIndex < 1 || shapeIndex > NUM_SHAPE) {
            std::cout << "Invalid shape index: " << shapeIndex << std::endl << std::endl;
            continue;
        }

        Shape *shape = shapeArray[shapeIndex - 1];
        std::cout << "You chose " << shape->getName() << "." << std::endl;
        std::cout << "The shape is in " << translateColor(shape->getColor())
                  << " color." << std::endl;
        shape->rotate(30);
        shape->playSound();

        std::cout << std::endl;
    } while (shapeIndex > 0);

    // Extra test: Amorphous
    auto *amorphous = dynamic_cast<Amorphous *>(shapeArray[4]);
    amorphous->playSound(std::string_view("This is a piece of custom sound."));

    return 0;
}