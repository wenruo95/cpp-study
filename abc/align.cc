#include<iostream>

// alignof 对齐

struct things1 {
	char ch;
	int a;
	double x;
};

struct things2 {
	int a;
	double x;
	char ch;
};

int main(void) {
	things1 th1;
	things2 th2;
	std::cout << "char alignment:" << alignof(char) << std::endl;
	std::cout << "int alignment:" << alignof(int) << std::endl;
	std::cout << "double alignment:" << alignof(double) << std::endl;
	std::cout << "things1 alignment:" << alignof(things1) << std::endl;
	std::cout << "things2 alignment:" << alignof(things2) << std::endl;
	std::cout << "sizeof things1:" << sizeof(things1) << std::endl;
	std::cout << "sizeof things2:" << sizeof(things2) << std::endl;
	return 0;
}
