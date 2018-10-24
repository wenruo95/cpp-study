#include<iostream>
#include<string>

class Test {
	public:
		std::string str;
		Test() {
			str = "test0";
			std::cout << "Test" << std::endl;
		}
		virtual void f() {
			std::cout << str << std::endl;
		}
		void f1() {
			std::cout << "test1" << std::endl;
		}
		void f2() {
			this->f();
		}
};

class TestS : public Test {
	public:
		std::string str;
		TestS() {
			str = "tests0";
			std::cout << "TestS" << std::endl;
		}
		void f() {
			std::cout << str << std::endl;
		}
		void f1() {
			std::cout << "tests1" << std::endl;
		}
		void f2() {
			this->f();
		}
};

int main(void) {
	Test *pt = NULL;

	Test test1;
	TestS test2;
	std::cout << std::endl;

	pt = &test1;
	pt->f();
	pt->f1();
	pt->f2();
	std::cout << std::endl;

	pt = &test2;
	pt->f();
	pt->f1();
	pt->f2();

}


