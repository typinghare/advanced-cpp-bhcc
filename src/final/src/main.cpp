#include <iostream>
#include "util/jest.h"
#include "entity/entities.h"

void test() {
    Category categoryAutomobile(1, "Automobile");
    Subcategory subcategoryGas(1, "Gas", categoryAutomobile);
    Subcategory subcategoryLoan(2, "Loan", categoryAutomobile);


    Record record1(1, Date(2023, 10, 2), categoryAutomobile, subcategoryGas, -50.6);
    Record record2(2, Date(2023, 9, 15), categoryAutomobile, subcategoryLoan, -327.1);

    describe("Basic tests", [record1, record2]() {
        expect(record1.getId()).toBe(1);
        expect(record2.getAmount()).toBe(-327.1);

        expect(record1.getDate().getDay()).toBe(2);
        expect(record2.getCategory().getId()).toBe(1);
        expect(record2.getSubcategory().getId()).toBe(2);
    });
}

int main() {
    std::cout << "Starting BudgetWise..." << std::endl;
    std::cout << "BudgetWise Started." << std::endl << std::endl;

    // Test code template
//    describe("Simple tests", []() {
//        expect(5).toBe(6);
//        expect(5.0).toBe(5.0);
//    });

    test();

    return 0;
}