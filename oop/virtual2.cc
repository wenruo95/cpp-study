#include<iostream>

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

int main(void) {
	(new Base())->f();
	std::cout << std::endl;

	Derived deri;
	deri.f();
	deri.g();
	deri.Base::g();

	std::cout << std::endl;

	Base *pb = new Derived();
	pb->f();
	pb->g();
	pb->Base::f();
	pb->Base::g();

	std::cout << std::endl;
}
