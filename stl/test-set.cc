#include<iostream>

#include <algorithm>
#include<set>

int main(void) {
	std::set<unsigned int> set1;
	set1.insert(1);
	set1.insert(10);
	set1.insert(12);
	set1.insert(13);
	set1.insert(14);
	set1.insert(15);

	std::set<unsigned int> set2;
	set2.insert(1);
	set2.insert(2);
	set2.insert(12);
	set2.insert(15);
	set2.insert(18);
	set2.insert(19);
	set2.insert(20);

	std::set<unsigned int> set3;
	std::set<unsigned int>::iterator iter = set3.begin();
	std::set_intersection(set1.begin(), set1.end(),
			set2.begin(), set2.end(),
			std::inserter(set3, iter));

	for (std::set<unsigned int>::iterator it = set3.begin(); it != set3.end(); it++) {
		std::cout << *it << std::endl;
	}

}
