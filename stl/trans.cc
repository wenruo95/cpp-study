#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

int main(void) {
	string str = "abc";
	char ch[4];
	int i;
	for (i = 0; i < str.length(); i++) {
		ch[i] = str[i];
	}
	ch[i] = '\0';
	vector<char> vec(str.begin(),str.end());
	vector<string> arr;
	arr.push_back(str);
	arr.push_back("123");

	std::cout << "string:" << str << "\n";
	std::cout << "vec_char:" << ch << "\n";
	for (vector<string>::iterator it = arr.begin(); it != arr.end(); it++) {
		std::cout << "vec_string:" << *it << "\n";
	}

	for (int i = 0; i != vec.size(); i++) {
		std::cout << i << ":" << vec[i] << std::endl;
	}

	// 二维数组
	vector<vector<string>> vec2;
	vector<string> a,b;
	a.push_back("abc1");
	a.push_back("abc2");
	a.push_back("abc3");

	b.push_back("abc4");
	b.push_back("abc5");
	b.push_back("abc6");
	
	vec2.push_back(a);
	vec2.push_back(b);
	for (vector<vector<string>>::iterator it = vec2.begin(); it != vec2.end(); it++) {
		for (vector<string>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
			std::cout << "vec_string2:" << *it2 << "\n";
		}
	}
	std::cout << "gg:" << vec2[1][0] << std::endl;
}
