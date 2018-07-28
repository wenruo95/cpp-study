#include<iostream>

#include<string>
#include<map>
#include<set>

int main() {
	std::map<int,std::set<int>> m;

	std::set<int> set_int;
	set_int.insert(1);
	set_int.insert(2);
	set_int.insert(3);
	set_int.insert(4);
	m[10] = set_int;

	std::set<int> set2 = m[9];
	set2.insert(10);
	m[9] = set2;
	m[8] = set2;


	for (std::map<int,std::set<int>>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << "int:\t" << it->first << std::endl;
		std::set<int> mset = it->second;
		for (std::set<int>::iterator it2 = mset.begin(); it2 != mset.end(); it2++) {
			std::cout << "set_int:\t" << *it2 << std::endl;
		}
	}
}
