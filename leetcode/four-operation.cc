#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	int four_operation(std::string str) {
		int current = 0, sum = 0;
		int left = 0, middle = 0, right = 0;
		int size = str.size();
		for (int i = 0; i < size; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				current = current * 10 + (str[i] - '0');
			} else {
				switch str[i] : {
					case '+':
					case '-': {
						if (middle == 0) {
							middle = current;
						} else {
							left
						}
					}; break;
					case '*':
					case '/': {
						
					}
				}
			}
		}
		stack.push(nums, current);
		return 10;
	}
};

int main(void) {
	Solution solution;
	std::string str1 = "12*24/3+2*3";
	//std::string str2 = "12*24/(3+2*3)";
	std::cout << str1 << "\t" << solution.four_operation(str1) << std::endl;
	std::cout << str2 << "\t" << solution.four_operation(str2) << std::endl;

}
