#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		/* 要求nums升序排列
		int low = 0, high  = nums.size() - 1;
		while (low <= high) {
			int sum = nums[low] + nums[high];
			if (sum == target) {
				return {low, high};
			} else if (sum > target) {
				high--;
			} else {
				low++;
			}
		}
		return {0,0};
		*/
		/*
		for (int i = 0; i != nums.size(); i++) {
			for (int j = i + 1; j != nums.size(); j++) {
				if (target == nums[i] + nums[j]) {
					return {i,j};
				}
			}
		}
		return {0,0};
		*/
		map<int,int> m;
		int temp;
		for (int i = 0; i != nums.size(); i++) {
			temp = target - nums[i];
			if (m.find(temp) == m.end()) {
				m[nums[i]] = i;
			} else {
				return {m[temp],i};
			}
		}
		return {0,0};
	}
};

int main () {
	Solution solution;
	vector<int> v = {2,7,11,15};
	int target = 9;
	vector<int> result = solution.twoSum(v,target);
	for (int i = 0; i != result.size(); i++) {
		std::cout << result[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}


