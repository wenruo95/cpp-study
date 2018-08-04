#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>


int main(void) {
	/*
	std::vector<std::string> vec;
	vec.push_back("abc");
	vec.push_back("bc");
	vec.push_back("dfgh");
	vec.push_back("bcd");
	vec.push_back("efg");
	vec.push_back("acdf");
	vec.push_back("ghi");

	std::string target;
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++) {
		target += *it;
	}
	std::cout << "target:" << target << std::endl;
	*/


	// 将list转换成target字符串
	std::string target("abcbcdfghbcdefgacdfghi");

	unsigned int maxlength = 5;

	std::set<std::string> reg;
	reg.insert("cd");
	reg.insert("e");
	reg.insert("fg");
	reg.insert("hi");

	// reg
	for (std::set<std::string>::iterator it = reg.begin(); it != reg.end(); it++) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	std::vector<std::string> results;
	for (int i = 0; i < target.size(); i++) {
		unsigned int tail = i;
		while (tail - i < maxlength && tail < target.size()) {
			std::string temp(&target[i], &target[tail + 1]);
			if (reg.find(temp) != reg.end()) {
				results.push_back(temp);
				i = tail;
				break;
			}
			tail++;
		}
	}

	for (std::vector<std::string>::iterator it = results.begin(); it != results.end(); it++) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

}
