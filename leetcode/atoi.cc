#include<iostream>
#include<string>
#include<climits>

using std::string;

class Solution {
public:
	int reverse(string str) {
		if (x == 0) {
			return x;
		}
		unsigned int real_num = (x > 0) ? x : -x;
		unsigned int head = (x > 0) ? (INT_MAX / 10) : -(INT_MIN / 10);
		unsigned int tail = (x > 0) ? (INT_MAX % 10) : -(INT_MIN % 10);
		int result = 0;
		while (real_num > 0) {
			unsigned int last_num = real_num % 10;
			if (result > head || (result == head && last_num > tail)) {
				return 0;
			}
			result = result * 10 + last_num;
			real_num = real_num / 10;
		}
		return (x > 0) ? result : -result;
	}
};

int main(void) {
	std::cout << INT_MIN << "\t" << INT_MAX << std::endl;
	Solution solution;
	int a = 123;	// 321
	int b = -123;	// -321
	int c = 120;	// 21
	int d = 1534236469;
	std::cout << a << "\t" << solution.reverse(a) << std::endl;
	std::cout << b << "\t" << solution.reverse(b) << std::endl;
	std::cout << c << "\t" << solution.reverse(c) << std::endl;
	std::cout << d << "\t" << solution.reverse(d) << std::endl;
}
