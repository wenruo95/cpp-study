#include<iostream>
#include<vector>

int main(void) {
	int arr[10];
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		std::cout << "array " << i << " input:";
		std::cin >> arr[i];
	}
	int temp;
	for (int i = 0; i < 10; i++) {
		std::cout << "vector " << i << " input:";
		std::cin >> temp;
		v.push_back(temp);
	}

	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i < 10; i++) {
		sum += arr[i];
		sum1 += v[i];
	}
	std::cout << "\narray sum:" << sum << " \taverage:" << sum / 10 << std::endl;
	std::cout << "vector1 sum:" << sum1 << " \taverage:" << sum1 / 10 << std::endl;

	int sum2 = 0;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		sum2 += *it;
	}
	std::cout << "vector2 sum:" << sum2 << " \taverage:" << sum2 / 10 << std::endl;

	return 0;
}
