#include<iostream>

#include<string>
#include<vector>
#include<set>
#include<list>
#include<map>


//using namespace std;
using std::string;
using std::vector;
using std::set;
using std::list;
using std::map;

void stl_string();
void stl_vector();
void stl_set();
void stl_list();
void stl_map();

int main(void) {
	std::cout << "Helloworld!!!" << std::endl;
	/*
	stl_string();
	stl_vector();
	stl_set();
	*/
	stl_list();
	stl_map();
	return 0;
}


// stl ==> string
void stl_string() {
	std::cout << "\n\nstring.start---------------" << std::endl;
	/*
	char *str = "helloworld";		// 字符串不能修改
	char str2[20] = "helloworld";
	char str3[] = "helloworld";
	char str4 = (char *) malloc(20 * sizeof(char));
	gets(str4);
	*/
	
	string s1;
	string s2 = s1;
	string s3 = "helloworld";
	string s4 = string(10,'a');
	string s5(s4);
	string s6("HelloWorld");
	string s7 = string(6,'c');
	// +号左右至少有一个是string
	string s8 = s3 + s6;
	s3 = s6;
	std::cout << "please input s1:";
	std::cin >> s1;

	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;
	std::cout << "s3:" << s3 << std::endl;
	std::cout << "s4:" << s4 << std::endl;
	std::cout << "s5:" << s5 << std::endl;
	std::cout << "s6:" << s6 << std::endl;
	std::cout << "s7:" << s7 << std::endl;
	std::cout << "s8:" << s8 << std::endl;
	std::cout << "s1.size:" << s1.size() << std::endl;
	std::cout << (s2.empty() ? "empty" : "not empty") << std::endl;

	for (int i = 0; i < s1.size(); i++) {
		std::cout << s1[i];
		s1[i] = 'a';
	}

	std::cout << "\nafter1:" << s1 << std::endl;

	for (string::iterator it = s1.begin(); it != s1.end(); it++) {
		std::cout << *it;
		*it = 'c';
	}

	std::cout << "\nafter2:" << s1 << std::endl;

	// iterator
	for (string::const_iterator it = s1.begin(); it != s1.end(); it++) {
		std::cout << *it;
	}

	std::cout << "\nafter3:" << s1 << std::endl;

	std::cout << (s1 > s3) << std::endl;

	std::cout << "string.end---------------" << std::endl;
}

// stl ==> vector
void stl_vector() {
	std::cout << "\n\nvector.start---------------" << std::endl;
	vector<int> v1 = { 10,9,8,7,6 };
	v1.push_back(3);

	std::cout << "empty:" << v1.empty() << "\tsize:" << v1.size() << "\t" << std::endl;

	for (int i = 0; i != v1.size(); i++) {
		std::cout << i << ":" << v1[i] << std::endl;
	}

	std::cout << "iterator" << std::endl;
	
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		std::cout << *it << std::endl;
	}

	// 反向遍历
	std::cout << "god wei iterator" << std::endl;
	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		std::cout << *it << std::endl;
	}

	std::cout << "vector.end---------------" << std::endl;
}

// stl ==> set:类似vector但是有序且唯一
void stl_set() {
	std::cout << "\n\nset.start---------------" << std::endl;
	set<int> s1 = {1,5,3,4,9,6,7,7,7,1,5,8};
	s1.insert(13);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "set.end---------------" << std::endl;
}

// stl ==> list
void stl_list() {
	std::cout << "\n\nlist.start---------------" << std::endl;
	list<int> lst = {1,5,3,4,5,7,2};
	lst.push_back(13);
	lst.push_front(12);
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::cout << "list.end---------------" << std::endl;
}

// stl ==> map
void stl_map() {
	std::cout << "\n\nmap.start---------------" << std::endl;
	map<string,int> m;
	m["zw"] = 100;
	m["linkzw"] = 99;
	m["wenruo"] = 99;
	m["linkzw"] = 98;
	for (map<string,int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	std::cout << m.contains("test") << std::endl;
	if (m.contains("test")) {
		std::cout << "not exist" << std::endl;
	} else {
		std::cout << "exist" << std::endl;
	}
	std::cout << "map.end---------------" << std::endl;

}

