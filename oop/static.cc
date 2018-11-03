#include<iostream>

class Base {
public:

	//const
	static int count;

	void f() {
		std::cout << "Base f()" << std::endl;
	}
};

int Base::count = 10;

int main(void) {
	std::cout << Base::count << std::endl;

	Base::count = 15;
	std::cout << Base::count << std::endl;

}
