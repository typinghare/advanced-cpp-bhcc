#include <iostream>
#include <vector>

using namespace std;

class Outer {
private:
    int foo;
public:
    explicit Outer(int foo) : foo(foo) {}

    class Inner {
    public:
        int bar(const Outer &outer) {
            // Access outer class private properties
            return outer.foo * 2;
        }
    };
};

int main() {
    Outer outer{5};
    Outer::Inner inner;

    std::cout << inner.bar(outer) << std::endl;

    return 0;
}

