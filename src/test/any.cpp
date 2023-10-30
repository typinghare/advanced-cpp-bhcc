#include <iostream>

using namespace std;

int main() {
    // 1. Count repeating numbers
    std::vector<int> numbers = {1, 0, 2, 0, 1, 0, 2, 1, 0};
    std::cout << std::count(numbers.begin(), numbers.end(), 0) << std::endl;

    // 2. Count repeating characters of a string
    std::string str = "abcbcacbcbccababbaa";
    std::cout << std::count(str.begin(), str.end(), 'b') << std::endl;

    // 3. Count with a unary predicate
    auto predicate = [](int number) {
        return number != 0;
    };
    std::cout << std::count_if(numbers.begin(), numbers.end(), predicate) << std::endl;
}

