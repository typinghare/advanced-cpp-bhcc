#include <iostream>
#include <string_view>

using namespace std;


class MyClass {
public:
    MyClass(double value);

    MyClass(string_view value);

private:
    double stringToDouble(std::string_view inString) const;

    double mValue;

};

MyClass::MyClass(double value) : mValue(value) {
    cout << "MyClass double constructor \n";
}

MyClass::MyClass(string_view value) : MyClass(stringToDouble(value)) {
    cout << "MyClass string_view constructor \n";
}

double MyClass::stringToDouble(std::string_view inString) const {
    return strtod(inString.data(), nullptr);
}

int main() {
    MyClass instance("1.2");
    return 0;
}