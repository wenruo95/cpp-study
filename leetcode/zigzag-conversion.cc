#include<iostream>
#include<string>

using std::string;

class Solution {
public:
	// 法一：通项公式
	// 法二: 字符串
	string convert(string s, int rows) {
		int count = 0, len = s.size(), column;
		if (len <= 1) {
			return s;
		}
		for (column = 0; rows * column + (column - 1) * (rows - 2) <= len; column++);
		std::cout << "column1:" << column << std::endl;
		//column += len - ((column * rows) + (column - 1) * (rows - 2));
		column = 2 * (column - 1) + 1;
		std::cout << "column2:" << column << std::endl;
		char ch[len + 1];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				int column_int = j / (rows - 1), pos = -1;
				if (j % (rows - 1) == 0) {
					pos = i + column_int * rows + column_int * (rows - 2);
				} else if ((i > 0) && (i < rows -1) && (i + j == (column_int + 1) * (rows - 1))){
					pos = (rows - 1) + 2 * column_int * (rows - 1) + j - (column_int + (column_int - 1) * (rows - 2) + 1);
				}
				if (pos >= 0 && pos < len) {
					ch[count++] = s[pos];
				}
			}
		}
		ch[count++] = '\0';
		return string(ch);
	}
};

int main() {
	Solution solution;
	string str("PAYPALISHIRING");
	std::cout << "test1:" << str.size() << "\n" << solution.convert(str,3) << std::endl; 
	std::cout << "PAHNAPLSIIGYIR" << std::endl;
	std::cout << "test2:" << str.size() << "\n" << solution.convert(str,4) << std::endl; 
	std::cout << "PINALSIGYAHRPI" << std::endl;
}
