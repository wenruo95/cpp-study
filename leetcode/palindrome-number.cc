#include<iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		} else if (x < 10) {
			return true;
		}
		char ch[10];
		unsigned int size = 0;
		unsigned int num = x;
		while (num > 0) {
			ch[size] = '0' + num % 10;
			num = num / 10;
			size++;
		}
		int left = (size - 1) - (size / 2);
		int right = size / 2;
		for (; left >= 0 && right < size && ch[left] == ch[right]; left--,right++);
		if (left < 0) {
			return true;
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	int x = 121;
	int y = -121;
	int z = 10;
	std::cout << x << "\t" << solution.isPalindrome(x) << std::endl;
	std::cout << y << "\t" << solution.isPalindrome(y) << std::endl;
	std::cout << z << "\t" << solution.isPalindrome(z) << std::endl;
}
