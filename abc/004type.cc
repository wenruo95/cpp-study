#include<iostream>

int main(void) {
	unsigned int age = 22;
	unsigned int *pint = &age;

	double height = 182.2;
	double *pd = &height;

	std::cout << "addres age:" << pint << "\tvalue of age:" << *pint << std::endl;
	std::cout << "addres height:" << pd << "\tvalue of height:" << *pd << std::endl;

	std::cout << "int size:" << sizeof age << "\t*int size:" << sizeof *pint << std::endl;
	std::cout << "doubel size:" << sizeof height << "\t*double size:" << sizeof *pd << std::endl;
}
