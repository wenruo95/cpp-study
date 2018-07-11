#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<map>

using std::string;

class Solution {
public:
	/* method1 leetcode无法通过机测无问题
	int lengthOfLongestSubstring(string s) {
		int len = 0, max = 0;
		unsigned int key = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!isrepeat(key,s[i] - 'a' + 1)) {
				key = key | (1 << (s[i] - 'a' + 1));
				len++;
				max = (len > max) ? len : max;
			} else {
				// 碰到相同的重新计算len
				int pos;
				for (pos = i - len; pos < i && s[i] != s[pos]; pos++) {
					key = key ^ (1 << (s[pos] - 'a' + 1));
				}
				len = i - pos;
				//std::cout << s[i] << "\t" << i << "\t" << pos << "\t" << len << "\t" << std::bitset<32>(key) << std::endl;
			}
		}
		return max;
	}
	*/
	int lengthOfLongestSubstring(string s) {
		int len = 0, max = 0;
		std::map<int,int> m;
		for (int i = 0; i < s.size(); i++) {
			if ((m.find(s[i] + 1) != m.end()) || m.size() == 0) {
				len++;
				m[s[i] + 1] = i;
				max = (len > max) ? len : max;
			} else {
				int pos;
				for (pos = i - len; pos < i && s[i] != s[pos]; pos++) {
					m.erase(s[i] + 1);
				}
				std::cout << s[i] << "\t" << i << "\t" << len << "\t" << pos << m.size() << std::endl;
				len = i - pos;
			}
		}
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
	// tmmzuxt 5
	std::vector<string> vs = {"abcabcbb","bbbbb","pwwkew","tmmzuxt"};
	Solution solution;
	for (int i = 0; i < vs.size() - 3; i++) {
		std::cout << vs[i] << " length:" << solution.lengthOfLongestSubstring(vs[i]) << std::endl;
	}
	return 0;
}
