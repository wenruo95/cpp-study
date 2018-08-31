#include<iostream>
#include<string>
#include<climits>

using std::string;

class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0) {
			return 0;
		}
		int left = -1, right = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '-' || str[i] == '+') {
				if (left == -1) {
					left = i;
					continue;
				} else {
					break;
				}
			}
			if (str[i] == ' ') {
				if (left == -1) {
					continue;
				} else {
					break;
				}
			}
			if (str[i] > '9' || str[i] < '0') {
				break;
			}
			if (left == -1) {
				left = i;
			}
			right = i;
		}

		// 首个为字母
		if (left == -1 || right < left) {
			return 0;
		}
		int x = (str[left] == '-') ? -1 : 1;
		if (str[left] == '-' || str[left] == '+') {
			left++;
		}
		//
		//std::cout << str << "\tleft:\t" << left << "\trigth:\t" << right << std::endl;
		std::string chs(&str[left], &str[right + 1]);
		unsigned int head = (x > 0) ? (INT_MAX / 10) : -(INT_MIN / 10);
		unsigned int tail = (x > 0) ? (INT_MAX % 10) : -(INT_MIN % 10);
		int result = 0;
		for (int i = 0; i < chs.size(); i++) {
			unsigned int last_num = chs[i] - '0';
			if (result > head || (result == head && last_num > tail)) {
				return x > 0 ? INT_MAX : INT_MIN;
			}
			result = result * 10 + last_num;
		}
		return x * result;
	}
};

int main(void) {
	Solution solution;
	std::string str1 = "42"; // 42
	std::string str2 = "    -42"; // -42
	std::string str3 = "4193 with words"; // 4193
	std::string str4 = "words and 987"; // 0
	std::string str5 = "-91283472332"; // -2147483648
	std::string str6 = "   - 321"; // -2147483648
	std::string str7 = "+1"; // -2147483648
	std::cout << str1 << "\t" << solution.myAtoi(str1) << std::endl;
	std::cout << str2 << "\t" << solution.myAtoi(str2) << std::endl;
	std::cout << str3 << "\t" << solution.myAtoi(str3) << std::endl;
	std::cout << str4 << "\t" << solution.myAtoi(str4) << std::endl;
	std::cout << str5 << "\t" << solution.myAtoi(str5) << std::endl;
	std::cout << str6 << "\t" << solution.myAtoi(str6) << std::endl;
	std::cout << str7 << "\t" << solution.myAtoi(str7) << std::endl;
}

