#include <iostream>
#include <map>
 
using std::map;

int main()
{  
	std::cout << __cplusplus << std::endl;

	std::map<int,char> m = {{1,'a'},{2,'b'}};
	// m.contains c++20
	if(m.find(2) != m.end()) {
		std::cout << "Found\n";
	} else {
		std::cout << "Not found\n";
	}
	//
	std::cout << "file:\t" << __FILE__ << std::endl;
	std::cout << "line:\t" << __LINE__ << std::endl;
	std::cout << "date:\t" << __DATE__ << std::endl;
	std::cout << "time:\t" << __TIME__ << std::endl;
	return 0;
}
