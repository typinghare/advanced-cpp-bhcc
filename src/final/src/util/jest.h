#ifndef ADVANCED_CPP_BHCC_JEST_H
#define ADVANCED_CPP_BHCC_JEST_H

#include <iostream>


/**
 * @warning All stuffs in this header file are still under construction.
 * @brief A wrapper class containing a value for testing.
 * @tparam T The type of the wrapped value.
 */
template<typename T>
class Jest {
private:
    T value;
public:
    explicit Jest(T value);

    void toBe(T expectedValue) const;
};

//template
//class Jest<short>;
//
//template
//class Jest<int>;
//
//template
//class Jest<double>;
//
//template
//class Jest<std::string>;

template<typename T>
class ToBeException : public std::exception {
private:
    T value;
    T expectedValue;

public:
    ToBeException(T value, T expectedValue) : value(value), expectedValue(expectedValue) {}

    [[nodiscard]] T getValue() const { return value; }

    [[nodiscard]] T getExpectedValue() const { return expectedValue; }
};

/**
 * @brief Creates and returns a Jest object with specified value.
 * @tParam T Template type of the value.
 * @param value The specified value to test with.
 */
template<typename T>
Jest<T> expect(T value);

/**
 * @brief Prints a value string and an expected value string.
 * @param valueStr
 * @param expectedValueStr
 */
void compare(const std::string &valueStr, const std::string &expectedValueStr);

/**
 * @brief Performs a test.
 * @param testName The name of the test case.
 * @param testLambda The lambda function to call.
 */
inline void describe(const std::string &testName, const std::function<void()> &testLambda) {
    std::cout << "TestBegin [" << testName << "]" << std::endl;

    bool caught = false;
    try {
        testLambda();
    } catch (const ToBeException<int> &e) {
        compare(std::to_string(e.getValue()), std::to_string(e.getExpectedValue()));
        caught = true;
    } catch (const ToBeException<double> &e) {
        compare(std::to_string(e.getValue()), std::to_string(e.getExpectedValue()));
        caught = true;
    }

    if (!caught) {
        std::cout << "All test cases passed." << std::endl;
    }

    std::cout << "TestEnd [" << testName << "]" << std::endl << std::endl;
}

#endif
