#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	std::string intToRoman(int num) {
		std::string str = "";
		if (num <= 0) {
			return str;
		}
		std::vector<int> vec_nums = {1,5,10,50,100,500,1000};
		std::vector<char> vec_chs = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		for (int i = vec_num.size() - 1; i >= 0; i--) {
			
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
