# C++ Crash Course

## Namespaces

Namespaces address the problem of naming conflicts between different pieces of code.

## Enumerations

~~~c++
// By default, the underlying type of enumeration value is integer
enum class MyEnum {
VALUE1,         // 0
VALUE1 = 10,    // 5
VALUE1,         // 6
};

// Set the underlying type as unsigned long
enum class MyLong: usigned long {
VALUE1,
VALUE2,
VALUE3
};
~~~

## Range-based for Loop

~~~c++
std::array<int, 4> arr = {1,2,3,4};
for (int i: arr) {
    std::cout << i << std::endl;
}
~~~

## Lambda Functions

~~~c++
void forEach(const std::vector<int> values, void(*func)(int) ) {
    for (int value: values) {
        func(value);
    }
}

std::vector<int> values = {1, 2, 3, 4, 5};
auto lambda = [](int value) { std::cout << "Value: " << value << std::endl; }
forEach(values, lambda);
~~~

~~~c++
#include <functional>

void forEach(const std::vector<int> values, std::function<void(int)>& func) {
    for (int value: values) {
        func(value);
    }
}
~~~

