#include<iostream>
#include<string>

using std::string;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}
		unsigned int low = 0, high = 0, maxlen = 0;
		for (int mid = 0; mid < s.size(); mid++) {
			int temp_len,left,right;
			if ((mid -1) >= 0 && (mid + 1 < s.size()) && (s[mid - 1] == s[mid + 1])) {
				temp_len = 3;
				left = mid - 2;
				right = mid + 2;
				while ((left >= 0) && (right < s.size()) && (s[left] == s[right])) {
					temp_len += 2;
					left--;
					right++;
				}
				if (temp_len > maxlen) {
					maxlen = temp_len;
					low = left + 1;
					high = right - 1;
				}
			}
			if ((mid + 1 < s.size()) && (s[mid] == s[mid + 1])) {
				temp_len = 2;
				left = mid - 1;
				right = mid + 2;
				while ((left >= 0) && (right < s.size()) && (s[left] == s[right])) {
					temp_len += 2;
					left--;
					right++;
				}
				if (temp_len > maxlen) {
					maxlen = temp_len;
					low = left + 1;
					high = right - 1;
				}
			}
		}
		return string(&s[low], &s[high + 1]);
	}
};

int main(void) {
	string str1 = "babad";
	string str2 = "cbbd";
	string str3 = "bb";
	string str4 = "ac";
	string str5 = "aaaa";
	Solution solution;
	std::cout << "org:" << str1 << "\tresult:" << solution.longestPalindrome(str1) << std::endl;
	std::cout << "org:" << str2 << "\tresult:" << solution.longestPalindrome(str2) << std::endl;
	std::cout << "org:" << str3 << "\tresult:" << solution.longestPalindrome(str3) << std::endl;
	std::cout << "org:" << str4 << "\tresult:" << solution.longestPalindrome(str4) << std::endl;
	std::cout << "org:" << str5 << "\tresult:" << solution.longestPalindrome(str5) << std::endl;
}
