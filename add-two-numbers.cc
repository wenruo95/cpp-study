#include<iostream>
#include<list>

using std::list;

int main(void) {
	list<int> list1 = {2,4,3};
	list<int> list2 = {5,6,4};
	list<int> list3;
	int a = 1, sum = 0;
	for (list<int>::iterator it = list1.begin(); it != list1.end(); it++) {
		sum += *it * a;
		a *= 10;
	}
	a = 1;
	for (list<int>::iterator it = list2.begin(); it != list2.end(); it++) {
		sum += *it * a;
		a *= 10;
	}
	while (sum > 0) {
		list3.push_back(sum % 10);
		sum /= 10;
	}
	for (list<int>::iterator it = list3.begin(); it != list3.end(); it++) {
		std::cout << *it << "->\t";
	}
	std::cout << std::endl;
	return 0;
}
