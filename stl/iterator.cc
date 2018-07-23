#include<iostream>

#include<vector>
#include<list>


/*
template <typename elemType>
void display(const vector<elemType> &vec, ostream &os) {
	std::vector<elemType>::const_iterator iter = vec.begin();
	std::vector<elemType>::const_iterator end_it = vec.end();

	for (; iter != end_it; iter++) {
		os << *iter << ' ';
	}
	os << std::endl
}
*/

template <typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value) {
	for (; first != last; first++) {
		if (value == *first) {
			return first;
		}
	}
	return last;
}

int main() {
	
	const int asize = 8;
	int arr[asize] = {1,1,2,3,5,8,13,21};

	std::vector<int> vec_arr(arr,arr + asize);
	std::list<int> list_arr(arr,arr + asize);

	int *a1 = find(arr,arr + asize,1024);
	if (a1 != (arr + asize)) {
		std::cout << "find array element:" << *a1 << std::endl;
	}
	
	std::vector<int>::iterator it = find(vec_arr.begin(), vec_arr.end(), 1024);
	if (it != vec_arr.end()) {
		std::cout << "find vector element:" << it << std::endl;
	}

	std::list<int>::iterator iter = find(list_arr.begin(), list_arr.end(), 1024);
	if (iter != list_arr.end()) {
		std::cout << "find list element:" << iter << std::endl;
	}

}
