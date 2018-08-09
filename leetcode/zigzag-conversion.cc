#include<iostream>
#include<string>

using std::string;

class Solution {
public:
	string convert(string s, int rows) {
		int count = 0, len = s.size(), column;
		if (len <= 1) {
			return s;
		}
		for (column = 0; rows * column + (column - 1) * (rows - 2) <= len; column++);
		column--;
		column += len - ((column * rows) + (column - 1) * (rows - 2));
		char ch[len + 1];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				int column_int = j % (rows - 1), pos = -1;
				std::cout << "rows:" << i << "\tcolumns:" << j << "\tcolumn_int:" << column_int << std::endl;
				if (column_int == 0) {
					pos = i + (j / (rows - 1)) * rows + (j / (rows - 1)) * (rows - 2);
				} else if ((i != 0) && (i != rows -1) && (i - j == 1 || j - i == 1)){
					pos = column_int * rows  - 1 + j - (column_int + (column_int - 1) * (rows - 2));
				}
				if (pos >= 0 && pos < len) {
					std::cout << "rows:" << i << "\tcolumns:" << j << "\tpos:" << pos << std::endl;
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
	std::cout << "test1:" << solution.convert(str,3) << std::endl; // "PAHNAPLSIIGYIR"
	//std::cout << "test2:" << solution.convert(str,4) << std::endl; // "PINALSIGYAHRPI"
}
