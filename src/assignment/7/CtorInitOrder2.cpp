#include <iostream>
using namespace std;

class Foo {
public:
	Foo(double value);
	
private:
	double mValue = 0;
};

Foo::Foo(double value) : mValue(value) {
	cout << "Foo::mValue = " << mValue << endl;
}

class Bar : Foo {
public:
	Bar(double value);
};

Bar::Bar(double value) : Foo(value) {
	cout << "Bar value = " << value << endl;
}

class MyClass {
public:
	MyClass(double value);

private:
	double mValue;
	Bar mBar;
};

MyClass::MyClass(double value)
	: mValue(value), mBar(mValue) {
	cout << "MyClass::mValue = " << mValue << endl;
}

int main() {
	MyClass instance(1.2);
	return 0;
}