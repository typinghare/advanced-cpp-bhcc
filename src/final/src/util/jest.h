#ifndef ADVANCED_CPP_BHCC_JEST_H
#define ADVANCED_CPP_BHCC_JEST_H

#include <iostream>

template<typename T>
class Jest {
private:
    T mValue;
public:
    explicit Jest(T value);

    bool toBe(T expectedValue) const;
};

/**
 * Program exits if the given value is not equal to the expected value.
 * @tParam T template type of the value and expected value.
 * @param value the real/given value.
 */
template<typename T>
inline Jest<T> expect(T value) {
    return Jest<T>(value);
}

/**
 * Perform a test.
 * @param testName the name of the test case.
 * @param testFunction test anonymous function.
 */
inline void describe(const std::string &testName, const std::function<void()> &testFunction) {
    std::cout << "TestBegin [" << testName << "]" << std::endl;

    try {
        testFunction();
    } catch (const std::exception &e) {
        std::cout << "Test failed due to an encountered exception: " << std::endl;
        std::cout << e.what() << std::endl;

        exit(1);
    }

    std::cout << "TestEnd [" << testName << "]" << std::endl << std::endl;
}

#endif
