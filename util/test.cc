#include<iostream>

#include "base.h"

int main() {
	int a = 10, b = 20;
	double c = 11.11, d = 22.22;
	std::cout << "before:\t" << a << "\t" << b << std::endl;
	swap(a, b);
	std::cout << "after:\t" << a << "\t" << b << std::endl;

	std::cout << "before:\t" << c << "\t" << d << std::endl;
	swap(c, d);
	std::cout << "before:\t" << c << "\t" << d << std::endl;
}
