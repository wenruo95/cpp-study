#include<iostream>
#include<vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		unsigned int max = 0;
		for (int i = 0; i < height.size(); i++) {
			for (int j = i + 1; j < height.size(); j++) {
				int min_height = height[i] > height[j] ? height[j] : height[i];
				unsigned int area = min_height * (j - i);
				max = area > max ? area : max;
			}
		}
		return max;
	}
};

int main(void) {
	Solution solution;
	std::vector<int> vec = {1,8,6,2,5,4,8,3,7};
	std::cout << solution.maxArea(vec) << std::endl;
}
