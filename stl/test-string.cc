#include<iostream>
#include<string>


int main(void) {
	int a = 10;
	std::string str = "test";
	std::string str2;
	str2.format("kk%s.%d",str, a);
	std::cout << str << std::endl;
	std::cout << str2 << std::endl;
}
