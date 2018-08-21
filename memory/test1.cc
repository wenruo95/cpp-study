#include<iostream>

struct A {
	void foo() {}
};

int main(void) {
	A a;
	std::cout << typeid(a).name() << std::endl;
	a.foo();
	std::cout << sizeof(a) << std::endl;
}
