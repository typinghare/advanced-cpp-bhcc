# Pointers

## Smart Pointers

### Unique Pointers

A unique pointer stores one pointer only. We can assign a different object by removing the current object from the
pointer.

~~~c++
/**
 * A simple class for representing a rectangle.
 */
class Rectangle {
private:
    int mLength;
    int mBreadth;
public:
    Rectangle(int length, int breadth) : mLength(length), mBreadth(breadth) {}
    [[nodiscard]] int area() const { return mLength * mBreadth; }
};

int main() {
    // Raw pointers
    auto *rawPointer = new Rectangle(2, 3);

    // Smart pointers (unique pointer)
    unique_ptr<Rectangle> smartPointer(new Rectangle(4, 6));

    // Prints areas
    cout << rawPointer->area() << endl;
    cout << smartPointer->area() << endl;

    return 0;
}
~~~