#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;

			if (nums.size() < 3) {
				return result;
			}

			int size = nums.size();
			std::sort(nums.begin(), nums.end());

			for (int i = 0; i < size; i++) {
				if (nums[i] > 0) {
					break;
				}

				if (i - 1 >= 0 && nums[i] == nums[i-1]) {
					continue;
				}

				int left = i + 1;
				int right = size - 1;
				while (left < right) {
					int sum = nums[i] + nums[left] + nums[right]; 
					if (sum == 0) {
						result.push_back({nums[i], nums[left], nums[right]});
						int last_left = nums[left], last_right = nums[right];
						while (left < right && last_left == nums[left]) left++;
						while (left < right && last_right == nums[right]) right--; 
					} else if (sum > 0) {
						right--;
					} else {
						left++;
					}
				}
			}

			return result;
		}
};

int main() {
	vector<vector<int>> inputs;
	inputs.push_back({-1, 0, 1, 2, -1, -4});
	inputs.push_back({0, 0, 0, 0});

	Solution solution;
	for (vector<int> arr : inputs) {
		std::cout << "[ ";
		for (int v : arr) {
			std::cout << v << " ";
		}
		std::cout << "]" << std::endl;

		vector<vector<int>> result = solution.threeSum(arr);

		for (vector<int> a : result) {
			for (int b : a) {
				std::cout << b << "\t";
			}
			std::cout << std::endl;
		}
	}

}
