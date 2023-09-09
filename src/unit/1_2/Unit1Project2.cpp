
/**
 * @note Requirements for Unit 1 Project 2 (Smart Pointers).
 * @link https://docs.google.com/document/d/1SbZNrvsrHTx5uF-wHuhnwOWeKoj8uQPJ76Yc6_dP4Z0/edit
 *
 * Create a program that demonstrates the difference between smart pointers and raw pointers. Use
 * unique pointers, not shared pointers, and demonstrate how each type of pointer is used when
 * passed to a function that changes the value of what the pointer points to.
 */

#include <iostream>
#include <memory>

using namespace std;

/**
 * Multiplies a number by two.
 * @param number A int raw pointer
 */
void multiplyByTwo(int *number) {
    *number = *number << 1;
}

/**
 * Multiplies a number by two.
 * @param number A int unique pointer
 */
void multiplyByTwo(unique_ptr<int> &number) {
    *number = *number << 1;
}

/**
 * A brief demonstration of unique pointers, which compares raw pointers with smart pointers.
 */
int main() {
    // Initialize a raw pointer and a smart pointer
    int *rawPointer = new int(5);
    unique_ptr<int> smartPointer = make_unique<int>(10);

    // Pass them to functions
    multiplyByTwo(rawPointer);
    multiplyByTwo(smartPointer);

    // Test their values
    cout << *rawPointer << endl;        // expect: 10
    cout << *smartPointer << endl;      // expect: 20

    // Raw pointer must be deleted when it will no longer be used
    delete rawPointer;

    return 0;
}