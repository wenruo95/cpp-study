#include<iostream>
#include<vector>
#include<string>
#include<map>

class Solution {
public:
	std::string intToRoman(int num) {
		std::string str("");
		if (num <= 0 || num >= 4000) {
			return str;
		}
		unsigned int base = 1;
		std::vector<int> release;
		while (num > 0) {
			unsigned int temp = num % 10;
			if (temp != 0) {
				release.push_back(temp * base);
			}
			base = base * 10;
			num = num / 10;
		}
		for (std::vector<int>::reverse_iterator it = release.rbegin(); it != release.rend(); it++) {
			str += num2str(*it);
			//std::cout << *it << "\t" << num2str(*it) << std::endl;;
		}
		return str;
	}
	int romanToInt(std::string s) {
		int nums[3][3] = {
			{1, 5, 10},
			{10, 50, 100},
			{100, 500, 1000}
		};
		char chs[3][3] = {
			{'I', 'V', 'X'},
			{'X', 'L', 'C'},
			{'C', 'D', 'M'}
		};
		std::map<char, int> mp;
		int row_size = sizeof(nums) / sizeof(nums[0]);
		int column_size = sizeof(nums[0]) / sizeof(nums[0][0]);
		for (int i = 0; i < column_size; i++) {
			for (int j = 0; j < column_size; j++) {
				mp[chs[i][j]] = nums[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
				//std::cout << s[i] << "\t" << s[i+1] << std::endl;
				//std::cout << mp[s[i]] << "\t" << mp[s[i+1]] << std::endl;
				sum += mp[s[i+1]] - mp[s[i]];
				i++;
			} else {
				sum += mp[s[i]];
			}
		}
		return sum;
	}
	std::string num2str(int num) {
		int nums[3][3] = {
			{1, 5, 10},
			{10, 50, 100},
			{100, 500, 1000}
		};
		char chs[3][3] = {
			{'I', 'V', 'X'},
			{'X', 'L', 'C'},
			{'C', 'D', 'M'}
		};
		int row_size = sizeof(nums) / sizeof(nums[0]);
		int column_size = sizeof(nums[0]) / sizeof(nums[0][0]);
		for (int i = 0; i < row_size; i++) {
			int counts = num / nums[i][0];
			// counts <= 10
			switch (counts) {
				case 1: case 2: case 3: {
					return std::string(counts, chs[i][0]);
				};
				case 4: {
					return std::string(1, chs[i][0]) + std::string(1, chs[i][1]);
				};
				case 5: {
					return std::string(1, chs[i][1]);
				};
				case 6: case 7: case 8: {
					return std::string(1, chs[i][1]) + std::string((counts - 5), chs[i][0]);
				};
				case 9: {
					return std::string(1, chs[i][0]) + std::string(1, chs[i][2]);
				};
				case 10: {
					return std::string(1, chs[i][2]);
				};
				default: {
					// pass
				}
			}
		}
		// 
		int counts = num / nums[row_size - 1][column_size - 1];
		if (counts > 1 && counts < 4) {
			return std::string(counts, chs[row_size - 1][column_size - 1]);
		}
		return std::string("");
	}
};

int main(void) {
	Solution solution;
	int vec[] = {3,4,9,58,1994,2000}; // III IV IX LVIII MCMXCIV MM
	unsigned int size = sizeof(vec) / sizeof(vec[0]);
	for (int i = 0; i < size; i++) {
		std::cout << vec[i] << std::endl;
		std::string str = solution.intToRoman(vec[i]);
		std::cout << str << std::endl;
		std::cout << solution.romanToInt(str) << std::endl;
		std::cout << std::endl;
	}
}
