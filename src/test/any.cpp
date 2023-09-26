#include <iostream>
#include <vector>

using namespace std;

int main() {
//    double radius = 180;
//    auto convertToRadians = [radius]() -> double {
//        const double PI = 3.1415926;
//        double radians = radius * PI / 180;
//        std::cout << "The radians is: " << radians << std::endl;
//
//        return radians;
//    };
//
//    std::cout << convertToRadians() << std::endl;

//    auto multiplyTwoNumbers = [](int num1, int num2) -> int {
//        return num1 * num2;
//    };
//
//    std::cout << multiplyTwoNumbers(5, 9) << std::endl;
//

//    int first = 5, second = 9;
//    auto scaleLambda = [&first, second]() -> void {
//        first *= second;
//    };
//
//    scaleLambda();
//    std::cout << first << std::endl;

//    double value1, value2;
//    value1 = 33.;
//    value2 = 4.;
//    double max = 0;
////    auto biggerLambda = [=, &max] { max = value1 > value2 ? value1 : value2; };
////    biggerLambda();
//
//    auto biggerLambda = [](double val1, double val2) -> double {
//        return val1 > val2 ? val1 : val2;
//    };
//
//    max = biggerLambda(value1, value2);
//    cout << max << endl;

    int value = 10;
    auto incrementByReference = [&value]() {
        value++;
    };

    auto incrementByCopy = [value]() mutable {
        value++;
    };

//    auto decrementLambda = [value]() mutable {
//        value--;
//    };
//    decrementLambda();

    incrementByReference();
    incrementByCopy();

    std::cout << "Decremented value: " << value << std::endl;

//    vector<int> vec(10);
//    int value = 1;
//    generate(begin(vec), end(vec), [&value] {
//        value = value << 1;
//        return value;
//    });
//    for (const auto &i: vec) {
//        cout << i << " ";
//    }
//
    return 0;
}


