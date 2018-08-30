#include<iostream>
#include<string>
#include<map>

int main(void) {
	std::string str1 = "test[1]";
	std::string str2 = "test[2]";
	std::string str3 = "test[3]";
	std::string str4 = "test[4]";
	std::map<std::string, int> m;
	m[str1] = 1;
	m[str2] = 10;
	m[str3] = 100;
	m[str4] = 1000;
	for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << "\t" << it->second << std::endl;
	}

}
