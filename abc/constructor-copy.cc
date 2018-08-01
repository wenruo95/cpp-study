#include<iostream>

class Human {
public:
	int age;
	Human(int age);
	Human(const Human &human);
	Human& operator=(const Human &human);
	~Human();
};

Human::Human(int age) {
	this->age = age;
}
Human::Human(const Human &human) {
	this->age = 2 * human.age;
}

Human& Human::operator=(const Human &human) {
	this->age = 4 * human.age;
}

Human::~Human() {
	std::cout << "析构" << std::endl;
}


int main() {
	Human human1(4);
	std::cout << "human1:" << human1.age << std::endl;
	Human human2(human1);
	std::cout << "human2:" << human2.age << std::endl;
	human1 = human2;
	std::cout << "human1:" << human1.age << std::endl;
}
