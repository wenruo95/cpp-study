#include<iostream>

// 友元函数
class Box {
	double width;
public:
	friend void showbox(Box);
	void setwidth(double wid);
};

void Box::setwidth(double wid) {
	width = wid;
}

void showbox(Box box) {
	std::cout << box.width << std::endl;
}

// 友元类
class Human {
	int _age;
public: 
	Human(int age);
	~Human();
	friend class Dog;
};

Human::Human(int age) : _age(age) {
	std::cout << "构造函数:\t" << _age << std::endl;
}

Human::~Human() {
	std::cout << "析构函数:\t" << _age << std::endl;
}

class Dog {
public:
	void showhuman(Human);
};

void Dog::showhuman(Human human) {
	std::cout << "Dog.showhuman:\t" << human._age << std::endl;
}

int main() {
	//
	Box box;
	box.setwidth(10.0);
	//std::cout << "test:\t" << box.width << std::endl;
	showbox(box);
	
	//
	Dog dog;
	Human human1(10);
	Human human2(20);

	// 析构函数执行两次的原因是系统调用默认拷贝函数的结果
	/*
	* 只要类里有指针变量就得自己写拷贝构造函数和赋值函数，但是你确认用不着这些函数时，
	* 可以把这些函数左private声明而不去实现它，这就防止了会有人调用它，也防止编译器去生成它们.
	*/
	dog.showhuman(human1);
	dog.showhuman(human2);


}



