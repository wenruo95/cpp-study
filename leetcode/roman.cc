#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	std::string intToRoman(int num) {
		std::string str = "";
		if (num <= 0 || num >= 4000) {
			return str;
		}

		std::vector<int> nums[3] = {
			{1, 5, 10},
			{10, 50, 100},
			{100, 500, 1000}
		};
		std::vector<std::string> chs[3] = {
			{"I", "V", "X"},
			{"X", "L", "C"},
			{"C", "D", "M"}
		};

		std::map<unsigned int, std::string> mp;
		for (int i = 0; i < 3; i++) {
			unsigned int step = num[i][0];
			if (num < step) {
				break;
			}
			// 1-3
			for (int j = num[i][0]; j <= nums[0][2]; j += step) {
				
			}
			// 4
			// 5-8
			// 9
			// 10
		}

		unsigned int base = 1;
		std::vector<int> release;
		while (num > 0) {
			unsigned int temp = num % 10;
			if (temp != 0) {
				unsigned target = temp * base;
			}
			base = base * 10;
		}
	}
};

int main(void) {
	Solution solution;
	std::vector<int> vec = {3,4,9,58,1994}; // III IV IX LVIII MCMXCIV
	for (int i = 0; i < vec.size(); i++) {
		std::cout << solution.intToRoman(vec[i]) << std::endl;
	}
}
