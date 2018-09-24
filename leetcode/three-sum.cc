#include<iostream>
#include<vector>
#include<map>
#include<set>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::map<int, int> mp;
		std::map<int, std::vector<int>> sums;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]] = i;
			for (int j = 0; j < nums.size(); j++) {
				if (i != j) {
					int target = nums[i] + nums[j];
					std::vector<int> vec1 = sums[target];
					vec1.push_back(i);
					vec1.push_back(j);
				}
			}
		}
		std::vector<std::vector<int>> results;
		std::map<int, std::set<int>> repeat_mp;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i == j || repeat_mp[nums[i]].find(nums[j]) != repeat_mp[nums[i]].end()) continue;
				repeat_mp[nums[i]].insert(nums[j]);
				repeat_mp[nums[j]].insert(nums[i]);
				int target = -(nums[i] + nums[j]);
				if (mp.find(target) != mp.end() && mp[target] != i && mp[target] != j) {
					std::vector<int> result;
					result.push_back(nums[i]);
					result.push_back(nums[j]);
					result.push_back(nums[mp[target]]);
					results.push_back(result);
				}
			}
			mp.erase(nums[i]);
		}
		return results;
	}
};

int main(void) {
	Solution solution;
	std::vector<int> vec1;
	vec1.push_back(-1);
	vec1.push_back(0);
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(-1);
	vec1.push_back(-4);
	
	std::vector<std::vector<int>> result = solution.threeSum(vec1);
	for (std::vector<std::vector<int>>::iterator it = result.begin();
			it != result.end(); it++) {
		for (std::vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end();
				it2++) {
			std::cout << *it2 << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}
