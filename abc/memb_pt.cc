#include<iostream>

// 成员解除引用运算符 `*` 和 `->*`

class Example {
private:
	int feet;
	int inches;
public:
	Example();
	~Example();
	Example(int ft);
	void show_in() const;
	void show_ft() const;
	void use_ptr() const;
};

Example::Example() {
	feet = 0;
	inches = 0;
}

Example::~Example() {

}

Example::Example(int ft) {
	feet = ft;
	inches = 12 * feet;
}

void Example::show_in() const {
	std::cout << inches << " inches" << std::endl;
}

void Example::show_ft() const {
	std::cout << feet << " feet" << std::endl;
}

void Example::use_ptr() const {
	Example yard(3);
	int Example::*pt;
	pt = &Example::inches;

	std::cout << "Set pt to &Example::inches:" << std::endl;
	std::cout << "this->pt:" << this->*pt << std::endl;
	std::cout << "yard.*pt:" << yard.*pt << std::endl;

	pt = &Example::feet;
	std::cout << "Set pt to &Example::feet:" << std::endl;
	std::cout << "this->pt:" << this->*pt << std::endl;
	std::cout << "yard.*pt:" << yard.*pt << std::endl;

	void (Example::*pf)() const;
	pf = &Example::show_in;
	std::cout << "Set pf to &Example::show_in:" << std::endl;
	std::cout << "Using (this->*pf):";
	(this->*pf)();
	std::cout << "Using (yard.*pf)():";
	(yard.*pf)();

}

int main(void) {
	Example car(15);
	Example van(20);
	Example garage;

	std::cout << "car.use_ptr() output:" << std::endl;
	car.use_ptr();

	std::cout << "\nvan.use_ptr() output:" << std::endl;
	van.use_ptr();
	return 0;
}




