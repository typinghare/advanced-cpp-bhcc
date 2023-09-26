/**
 * @note Requirements of Unit 1 Project 1.
 *
 * Create a program that utilizes two namespaces that you create. Your namespaces should each
 * contain at least two overloaded functions, and each namespace should have the same overloaded
 * function signatures, but the functions should indicate which namespace the function is in.
 * In your file that contains the main() function (testNamespaces.cpp), create the same overloaded
 * function signatures. In testNamespaces.cpp, create a function (demoNamespaces) that implements
 * one set of overloaded functions. You will have 7 functions total. In main, demonstrate the use
 * of each function in the different namespaces individually, as well as a call to demoNamespaces.
 *
 * @note changelog
 * 1. Added a global function "whereAmI" in testNamespaces.cpp; a corresponding test is added to the
 * main function.
*/

#include "americaNamespace.h"
#include "chinaNamespace.h"

/**
 * Implements one self of overloaded functions.
 */
void demoNamespaces() {
    china::earn(50.0);
    america::earn(50.0);
}

/**
 * @brief A function with the same overloaded function signatures.
 */
void whereAmI() {
    std::cout << "You are in the Global village." << std::endl;
}

/**
 * A demonstration of utilizing namespaces.
 */
int main() {
    // Test china namespace
    china::whereAmI();
    china::earn(5000);
    china::earn(166.7);
    std::cout << std::endl;

    // Test america namespace
    america::whereAmI();
    america::earn(3200);
    america::earn(106.7);
    std::cout << std::endl;

    // Test the global "whereAmI" function
    whereAmI();
    std::cout << std::endl;

    // Call demoNamespaces function
    demoNamespaces();

    return 0;
}