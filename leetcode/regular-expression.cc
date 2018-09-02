#include<iostream>
#include<string>

using std::string;

inline bool match_s(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return true;
	}
	return false;
}

inline bool match_p(char ch) {
	if ((ch >= 'a' && ch <= 'z') || ch == '.' || ch == '*') {
		return true;
	}
	return false;
}

class Solution {
public: 
	bool isMatch(string s, string p) {
		return true;
	}
};

int main(void) {
	Solution solution;
	//					false true	true	true	false
	std::string s[5] = {"aa", "aa", "ab", "aab", "mississippi"};
	std::string p[5] = {"a", "a*", ".*", "c*a*b", "mis*is*p*."};
	for (int i = 0; i < 5; i++) {
		std::cout << solution.isMatch(s[i], p[i]) << std::endl;
	}
	return 0;
}
