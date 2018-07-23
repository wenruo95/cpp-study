#include<iostream>
#include<string>

int main(void) {
	// string-style
	std::string firstname,lastname;
	std::cout << "please input your first name:";
	std::cin >> firstname;
	std::cout << "\nplease input your last name:";
	std::cin >> lastname;
	std::cout << "Hello, " << firstname << lastname << " ... and goodbye" << std::endl;

	// c-style
	char head[1024],tail[1024];
	std::cout << "\nc-style input your firstname:";
	std::cin >> head;
	std::cout << "\nc-style input your lastname:";
	std::cin >> tail;
	std::cout << "c-style " << head << tail << " ... and goodbye" << std::endl;

	char name[1024];
	int validate = 1;
	while (validate) {
		std::cout << "please input your name(more than 2 characters):";
		std::cin >> name;
		char *arr = name;
		int len;
		for (len = 0; *(arr + len) != '\0'; len++);
		if (len < 2) {
			continue;
		}
		std::cout << "hello," << name << std::endl;
		break;
	}
	return 0;
}
