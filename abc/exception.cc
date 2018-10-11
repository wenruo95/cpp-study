#include<iostream>

//http://www.runoob.com/cplusplus/cpp-exceptions-handling.html

double division(int a, int b) {
	if (b == 0) {
		throw "throw test b = 0";
	}
	return (a/b);
}

int main(void) {
	int a = 10, b = 0;
	double c = 0;
	try {
		c = division(a, b);
		std::cout << c << std::endl;
	} catch( const char* msg) {
		std::cout << "test catch" << std::endl;
		std::cerr << msg << std::endl;
	}
}
