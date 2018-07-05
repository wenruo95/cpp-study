#include<iostream>
#include<vector>
#include<string>

using std::string;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = 0, max = 0;
		int key = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!isrepeat(key,s[i] - 'a' + 1)) {
				key = key | (1 << (s[i] - 'a' + 1));
				len++;
				max = (len > max) ? len : max;
			} else {
				// 碰到相同的重新计算len
				int pos;
				for (pos = i - len; pos < i && s[i] != s[pos]; pos++) {
					key = key ^ (s[pos] - 'a' + 1);
				}
				len = i - pos;
			}
		}
		return max;
	}
private:
	int isrepeat(int key,int pos) {
		return ((key & (1 << pos)) != 0);
	}
};

int main(void) {
	// abcabcbb 3
	// bbbbb 1
	// pwwkew 3
	std::vector<string> vs = {"abcabcbb","bbbbb","pwwkew"};
	Solution solution;
	for (int i = 0; i < vs.size(); i++) {
		std::cout << vs[i] << " length:" << solution.lengthOfLongestSubstring(vs[i]) << std::endl;
	}
	return 0;
}
