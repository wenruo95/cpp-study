#include<iostream>
#include<string>

void print(int x = 10, int y = 20);

int main(void) {
	std::cout << "test" << std::endl;
	print(15);
}

void print(int x, int y) {
	std::cout << x << "\t" << y << std::endl;
}
