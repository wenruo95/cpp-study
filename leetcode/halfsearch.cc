#include<iostream>

class Solution {
public:
	// 二分查找
	int halfsearch(int target) {
		int arr[] = {1,2,3,4,5};
		int size = sizeof(arr) / sizeof(arr[0]);
		int left = 0, right = size - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			//std::cout << mid << "\t" << left << "\t" << right << std::endl;
			if (target == arr[mid]) {
				return mid;
			}
			if (target > arr[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
			mid = (left + right) / 2;
		}
		return -1;
	}
	// 循环有序数组 O(logN) 查找数字
	int halfsearch2(int target) {
		int arr[] = {4,5,1,2,3};
		int size = sizeof(arr) / sizeof(arr[0]);
		int left = 0, right = size - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			//std::cout << mid << "\t" << left << "\t" << right << std::endl;
			if (target == arr[mid]) {
				return mid;
			}
			// 右侧
			if (target > arr[mid] && arr[left] > target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
			mid = (left + right) / 2;
		}
		/*
		if (mid >= 0 && mid < size && arr[mid] == target) {
			return mid;
		}
		*/
		return -1;
	}
};

int main(void) {
	Solution solution;
	std::cout << solution.halfsearch(2) << std::endl;
	std::cout << solution.halfsearch2(2) << std::endl;
}
