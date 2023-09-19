#include <iostream>

using namespace std;
enum class SHAPE {
    CIRCLE = 1, SQUARE, TRIANGLE, RECTANGLE
};

string translate(enum SHAPE shapeNum) {
    switch (shapeNum) {
        case SHAPE::CIRCLE:
            return "circle";
        case SHAPE::RECTANGLE:
            return "rectangle";
        case SHAPE::SQUARE:
            return "square";
        case SHAPE::TRIANGLE:
            return "triangle";
        default:
            return "unknown";
    }
    return "unknown";
}

void rotate(enum SHAPE shapeNum, int degrees) {
    cout << translate(shapeNum) << " is rotated " << degrees << " degrees." << endl;
}

void playSound(enum SHAPE shapeNum) {
    switch (shapeNum) {
        case SHAPE::CIRCLE:
            cout << R"(Swing your partner round and round - Pitbull
)";
            break;
        case SHAPE::RECTANGLE:
            cout << R"(All in all it's just bricks in the wall - Pink Floyd
)";
            break;
        case SHAPE::SQUARE:
            cout << R"(Square or round, rich or poor
At the end of day and night all we want is more - Janelle Monae
)";
            break;
        case SHAPE::TRIANGLE:
            cout << R"(Triangle man hates particle man - They Might Be Giants)";
            break;
        default:
            cout << R"(Is this the real life?
Is this just fantasy? - Queen
)";
    }
}

int main() {
    SHAPE Circle = SHAPE::CIRCLE;
    SHAPE Rect = SHAPE::RECTANGLE;
    SHAPE Square = SHAPE::SQUARE;
    SHAPE Triangle = SHAPE::TRIANGLE;
    long shape = 0;
    do {
        cout << "Choose a shape: " << endl;
        cout << static_cast<long>(Circle) << ": " << translate(Circle) << endl;
        cout << static_cast<long>(Square) << ": " << translate(Square) << endl;
        cout << static_cast<long>(Triangle) << ": " << translate(Triangle) << endl;
        cout << static_cast<long>(Rect) << ": " << translate(Rect) << endl;
        cout << "0: quit\n";
        cout << ": ";
        cin >> shape;
        if (shape > 0) {
            cout << "You chose " << translate((SHAPE) shape) << endl;
            rotate((SHAPE) shape, 30);
            playSound((SHAPE) shape);
        }
    } while (shape > 0);
    return 0;
}