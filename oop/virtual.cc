#include<iostream>

/*
 * 定义一个函数为虚函数，不代表函数为不被实现的函数。
 * 定义他为虚函数是为了允许用基类的指针来调用子类的这个函数。
 * 定义一个函数为纯虚函数，才代表函数没有被实现。
 * 定义纯虚函数是为了实现一个接口，起到一个规范的作用，规范继承这个类的程序员必须实现这个函数。
 */

class Base {
public:
	virtual void f() {
		std::cout << "Base f()" << std::endl;
	}
	void g() {
		std::cout << "Base g()" << std::endl;
	}
};

class Derived : public Base {
public:
	void f() {
		std::cout << "Derived f()" << std::endl;
	}
	void g() {
		std::cout << "Derived g()" << std::endl;
	}
};

class Derived2 : public Base {
public:
	/*
	void f() {
		std::cout << "Derived2 f()" << std::endl;
	}
	*/
	void g() {
		std::cout << "Derived2 g()" << std::endl;
	}
};


int main(void) {
	Base base;
	Derived derived;

	//
	base.f();
	base.g();
	derived.f();
	derived.g();
	std::cout << std::endl;

	//
	Base &br = base;
	Derived &dr = derived;
	br.f();
	br.g();
	dr.f();
	dr.g();
	std::cout << std::endl;

	//
	Base *bp = &base;
	Derived *dp = &derived;
	bp->f();
	bp->g();
	dp->f();
	dp->g();
	std::cout << std::endl;

	br.Base::f();
	br.Base::g();
	dr.Base::f();
	dr.Base::g();
	std::cout << std::endl;

	Derived2 deri2;
	deri2.f();
	deri2.g();
	std::cout << std::endl;

}



