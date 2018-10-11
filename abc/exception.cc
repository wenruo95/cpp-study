#include<iostream>

//http://www.runoob.com/cplusplus/cpp-exceptions-handling.html
/*
 * std::exception
 * std::bad_alloc
 * std::bad_cast
 * std::bad_exception
 * std::bad_typeid
 * std::logic_error
 * std::domain_error
 * std::invalid_argument
 * std::length_error
 * std::out_of_range
 * std::runtime_error
 * std::overflow_error
 * std::range_error
 * std::underflow_error
 */

struct MyException: public std::exception {
	const char* what() const throw() {
		return "C++ Exception";
	}
};

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

	try {
		throw MyException();
	} catch (MyException e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << "exception" << std::endl;
	}
}
