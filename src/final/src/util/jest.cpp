#include "jest.h"

template<typename T>
Jest<T>::Jest(T value): value(value) {
}

template<typename T>
void Jest<T>::toBe(T expectedValue) const {
    if (value != expectedValue) {
        throw ToBeException<T>(value, expectedValue);
    }
}

template<>
void Jest<int>::toBe(int expectedValue) const {
    if (value != expectedValue) {
        throw ToBeException<int>(value, expectedValue);
    }
}

template<>
void Jest<short>::toBe(short expectedValue) const {
    if (value != expectedValue) {
        throw ToBeException<short>(value, expectedValue);
    }
}

template<>
void Jest<unsigned int>::toBe(unsigned int expectedValue) const {
    if (value != expectedValue) {
        throw ToBeException<unsigned int>(value, expectedValue);
    }
}

template<>
void Jest<double>::toBe(double expectedValue) const {
    if (value != expectedValue) {
        throw ToBeException<double>(value, expectedValue);
    }
}

template<typename T>
Jest<T> expect(T value) {
    return Jest<T>(value);
}

template<>
Jest<short> expect(short value) {
    return Jest<short>(value);
}

template<>
Jest<int> expect(int value) {
    return Jest<int>(value);
}

template<>
Jest<unsigned int> expect(unsigned int value) {
    return Jest<unsigned int>(value);
}

template<>
Jest<double> expect(double value) {
    return Jest<double>(value);
}

void compare(const std::string &valueStr, const std::string &expectedValueStr) {
    std::cout << "Expected: " << expectedValueStr << std::endl
              << "Given:    " << valueStr << std::endl;
}