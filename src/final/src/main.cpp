#include <iostream>
#include "util/jest.h"

int main() {
    std::cout << "Starting BudgetWise..." << std::endl;
    std::cout << "BudgetWise Started." << std::endl;

    expect("name").toBe("name");

    return 0;
}