#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>


int main(void) {
	std::vector<std::string> vec;
	vec.push_back("abc");
	vec.push_back("de");
	vec.push_back("fgh");
	vec.push_back("ijk");

	std::set<std::string> reg;
	reg.insert("cd");
	reg.insert("e");
	reg.insert("fg");
	reg.insert("hi");

	
	// 将list转换成target字符串
	std::string target;
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++) {
		target += *it;
	}
	std::cout << "target:" << target << std::endl;

	// reg
	for (std::set<std::string>::iterator it = reg.begin(); it != reg.end(); it++) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;


	// abcdefghijk
	std::map<int,int> splits;// start-end
	for (std::set<std::string>::iterator it = reg.begin(); it != reg.end(); it++) {
		int size = (*it).size();
		for (int i = 0; i + size < target.size(); i++) {
			std::string temp(&target[i], &target[i + size]); // 将[i,i+size)范围内的字符串赋值给temp
			if (temp.compare(*it) == 0) {
				splits[i] = i + size - 1;
			}
		}
	}

	for (std::map<int,int>::iterator it = splits.begin(); it != splits.end(); it++) {
		std::cout << "start:" << it->first << "\tend:" << it->second << std::endl;
	}

	std::vector<std::string> results;
	int begin = 0;
	for (int i = 0; i < target.size(); i++) {
		if (splits.find(i) != splits.end()) {
			std::string front(&target[begin], &target[i]);
			results.push_back(front);
			std::string tail(&target[i], &target[splits[i] + 1]);
			results.push_back(tail);
			begin = splits[i] + 1;
			i = splits[i];
		}
	}

	for (std::vector<std::string>::iterator it = results.begin(); it != results.end(); it++) {
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

}
