#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

vector<string> split(const string str,const char seperator) {
	
}

int main(void) {
	string str("abc bbc acb");

	vector<vector<string>> output1;
	vector<string> output2;

	int last_trim = -1,len = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			string str_temp(&str[last_trim+1],&str[i]);
			str_temp[str.length()] = '\0';
			output2.push_back(str_temp);
			last_trim = i;
		}
	}
	string str_temp(&str[last_trim+1],&str[str.length()]);
	str_temp[str.length() + 1] = '\0';
	output2.push_back(str_temp);

	vector<string> temp[3];
	for (int i = 0; i < output2.size(); i++) {
		temp[i].push_back(output2[i]);
		output1.push_back(temp[i]);
	}

	std::cout << "origin string:\t" << str << std::endl;

	std::cout << "output1[0][0]" << "\t" << output1[0][0] << std::endl;
	std::cout << "output1[1][0]" << "\t" << output1[1][0] << std::endl;
	std::cout << "output1[2][0]" << "\t" << output1[2][0] << std::endl;

	std::cout << "output2[0]" << "\t" << output2[0] << std::endl;
	std::cout << "output2[1]" << "\t" << output2[1] << std::endl;
	std::cout << "output2[2]" << "\t" << output2[2] << std::endl;


}




