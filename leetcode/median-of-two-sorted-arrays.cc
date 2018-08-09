#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public : 
	double findMedianSortedArrays(vector<int>& num1, vector<int> &num2) {
		unsigned int sumnum = num1.size() + num2.size();
		unsigned int mid1 = ceil(sumnum / 2.0), mid2 = ceil((sumnum + 1) / 2.0);
		int key1 = 0, key2 = 0, count = 0, score1;
		while (count <= mid2) {
			int score;
			if (key1 < num1.size() &&  (key2 >=  num2.size() || num1[key1] < num2[key2])) {
				score = num1[key1];
				key1++;
			} else {
				score = num2[key2];
				key2++;
			}
			count++;
			if (count == mid1) {
				if (mid1 == mid2) {
					return score / 1.0;
				}
				score1 = score;
			} else if (count == mid2) {
				return (score1 + score) / 2.0;
			}
		}
	}
};

int main(void) {
	vector<int> num1,num2;
	num1.push_back(1);
	num1.push_back(2);

	num2.push_back(3);
//	num2.push_back(4);

	Solution solution;
	double result = solution.findMedianSortedArrays(num1,num2);
	std::cout << result << std::endl;
}
