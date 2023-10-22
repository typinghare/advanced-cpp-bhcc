#include <iostream>

using namespace std;

// Normal variable
constexpr double E = 2.71828;

// Variable templates
template<typename T>
constexpr T PI{T{3.1415926}};

int main() {
    // 1. Using variable templates
    double pi{PI<double>};
    double circumference = 3 * pi;

    // 2. Using static_cast
    double num1 = 2 * static_cast<float>(E);

    // 3. Using (float)
    float num2 = 2 * (float) E;

    std::cout << circumference << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    return 0;
}


