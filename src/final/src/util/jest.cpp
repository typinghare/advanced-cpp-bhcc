#include "jest.h"

template<typename T>
Jest<T>::Jest(T value): mValue(value) {
}

template<typename T>
bool Jest<T>::toBe(T expectedValue) const {
    return mValue == expectedValue;
}

template
class Jest<int>;

template
class Jest<double>;

template
class Jest<std::string>;