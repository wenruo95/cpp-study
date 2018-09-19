#include<iostream>
#include<functional>

/*
 * [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {
 *	//函数体
 * };
 *
 * 1.lambda表达式被创建时拷贝 而非调用时才拷贝
 */

using foo = void(int);

void functional(foo f) {
	f(1);
}

int foo2(int para) {
	return para;
}

int foo3(int a, int b, int c) {
	return a + b + c;
}

int main(void) {
	/*
	 * 值捕获
	 */
	int v1 = 1;
	auto double_v1 = [v1] {
		return v1 * 2;
	};
	/*
	 * 引用捕获
	 */
	auto double_v2 = [&v1] {
		return v1 * 2;
	};

	v1 = 100;
	auto v2 = double_v1();
	auto v3 = double_v2();

	std::cout << "值捕获:\t" << v1 << "\t" << v2 << std::endl;
	std::cout << "引用捕获:\t" << v1 << "\t" << v3 << std::endl;

	// std::function
	auto f = [](int value) {
		std::cout << "aaa:\t" << value << std::endl;
	};
	functional(f);
	f(1);
	
	//
	std::function<int(int)> func = foo2;
	int important = 10;

	std::function<int(int)> func2 = [&](int value) -> int {
		return 1 + value + important;
	};
	std::cout << "bbb:\t" << func(10) << std::endl;
	std::cout << "bbb:\t" << func2(10) << std::endl;

	/*
	 * std::bind/std::placeholder
	 * 将参数1,2绑定到函数foo上，但是用std::placeholders::_1对第一个参数进行占位
	 * 这是调用bindfoo只需要提供第一个参数即可
	 */
	auto bindfoo = std::bind(foo3, std::placeholders::_1, 1, 2);
	std::cout << "ccc:\t" << bindfoo(1) << std::endl;

	/*
	 * 左值、右值、纯右值、将亡值
	 */
}

