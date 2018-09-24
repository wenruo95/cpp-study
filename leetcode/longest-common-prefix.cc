#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.size() < 1) {
			return std::string("");
		} else if (strs.size() == 1) {
			return strs[0];
		}
		std::string common = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			int pos = 0;
			int size_a = common.size();
			int size_b = strs[i].size();
			while (pos < size_a && pos < size_b && common[pos] == strs[i][pos]) {
				pos++;
			}
			common = std::string(&common[0], &common[pos]);
		}
		return common;
	}
};

int main(void) {
	Solution solution;
	std::vector<std::string> vec1;
	vec1.push_back("flower");
	vec1.push_back("flow");
	vec1.push_back("flight");
	std::cout << solution.longestCommonPrefix(vec1) << std::endl;

	std::vector<std::string> vec2;
	vec2.push_back("dog");
	vec2.push_back("racecar");
	vec2.push_back("car");
	std::cout << solution.longestCommonPrefix(vec2) << std::endl;
	return 0;
}
