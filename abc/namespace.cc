#include<iostream>
#include<string>

namespace first_space {
	void cout(std::string str) {
		std::cout << "first_space::cout:\t" << str << std::endl;
	}
}

namespace second_space {
	void cout(std::string str) {
		std::cout << "second_space::cout:\t" << str << std::endl;
	}
}


int main(void) {
	std::string str = "testkkk";
	std::cout << str << std::endl;
	first_space::cout(str);
	second_space::cout(str);
}
