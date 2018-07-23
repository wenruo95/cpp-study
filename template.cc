#include<iostream>

template <int N>

struct Factorial {
	enum { value = N * Factorial<N - 1>::value};
};

template <>
struct Factorial<0> {
	enum {value = 1};
};

// 函数模板
template <class T>
void swap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
};

// 类模板
/*
template <class a, class b>
class Test {

};
*/


int main() {
	int x = Factorial<4>::value;
	int y = Factorial<0>::value;
	std::cout << "x:" << x << "y:" << y << std::endl;
	int a(10),b(20);
	std::cout << "before:\t" << a << "\t" << b << std::endl;
	swap(a,b);
	std::cout << "after:\t" << a << "\t" << b << std::endl;
	char c = 'c',d = 'd';
	std::cout << "before:\t" << c << "\t" << d << std::endl;
	swap(c,d);
	std::cout << "after:\t" << c << "\t" << d << std::endl;

}
