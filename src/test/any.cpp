#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
    virtual ~Base() {}

    virtual void Foo() {};
};

class Derived : public Base {
public:
    ~Derived() {}  // Will also be virtual
    void Foo() {}; // Will also be virtual
};

int main() {
    return 0;
}