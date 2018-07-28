#include<iostream>
#include<string>

class Animal {
public:
	Animal();
	~Animal();
	void eat();
	void sleep();
	void setname(std::string name);
	void showname();
	//int _age;

protected:
	std::string _name;

private:
};

Animal::Animal() {
	std::cout << "Animal构造函数" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal析构函数" << _name << std::endl;
}

void Animal::eat(){
	std::cout << "Animal Eat" << std::endl;
}

void Animal::sleep(){
	std::cout << "Animal Sleep" << std::endl;
}

void Animal::setname(std::string name) {
	_name = name;
}

void Animal::showname() {
	std::cout << "Animal name:\t" << _name << std::endl;
}

class Human : public Animal{
public:
	Human();
	~Human();
	void eat();
	void sleep();
	void showname();
	void showage();
private:
};

Human::Human() {
	std::cout << "Human构造函数" << std::endl;
}

Human::~Human() {
	std::cout << "Human析构函数" << _name << std::endl;
}

void Human::eat() {
	std::cout << "Human Eat" << std::endl;
}

void Human::sleep() {
	std::cout << "Human Sleep" << std::endl;
}

void Human::showname() {
	std::cout << "Human name:\t" << _name << std::endl;
}

void Human::showage() {
	std::cout << "Human age:"<< std::endl;
}

int main(void) {
	Animal animal;
	animal.setname("t1");
	animal.eat();
	animal.sleep();
	animal.showname();
	std::cout << std::endl;

	/*
	Animal *animal2 = new Animal;
	animal2->eat();
	animal.sleep();
	animal2->showname();
	*/

	Human human1;
	animal.setname("t2");
	human1.eat();
	human1.sleep();
	human1.showname();
	human1.showage();
	std::cout << std::endl;

	/*
	Human human2;
	human2.eat();
	human2.sleep();
	human2.showname();
	human2.showage();
	*/

}
