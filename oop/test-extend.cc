#include<iostream>

class Base {
	public:
		int _length, _width, _height;
		Base();
		Base::Base(int len, int wid, int hgh);
		~Base();
		void setsize(int len, int wid, int height);
		int getarea();
	private:
		int _getarea();
};

Base::Base() {
	std::cout << "Base 构造函数" << std::endl;
}

Base::Base(int len, int wid, int hgh) : _length(len), _width(wid), _height(hgh) {
	std::cout << "Base 构造函数: " << _length << " " << _width << " " <<  _height << std::endl;
}

void Base::setsize(int len, int wid, int height) {
	_length = len;
	_width = wid;
	_height = height;
	std::cout << "Base setsize: " << _length << " " << _width << " " <<  _height << std::endl;
}

Base::~Base() {
	std::cout << "Base 析构函数" << std::endl;
}

int Base::getarea() {
	return _getarea();
}

int Base::_getarea() {
	return _length * _width * _height;
}


class Square : public Base {
	public:
		Square();
		Square(int len, int wid, int hgh);
};

Square::Square() {
	std::cout << "Square 构造函数" << std::endl;
}

//Square::Square(int len, int wid, int hgh) : Base(len, wid, hgh) {
Square::Square(int len, int wid, int hgh) : Base::Base(len, wid, hgh) {
	std::cout << "Square 构造函数2" << std::endl;
}

int main(void) {
	Base base;
	base.setsize(10, 20, 30);
	std::cout << "base.area: " << base.getarea() << std::endl;
	std::cout << std::endl;

	/*
	Square square;
	square.setsize(20, 30, 40);
	//std::cout << "square.length: " << square._length << std::endl;
	std::cout << "square.area: " << square.getarea() << std::endl;
	std::cout << std::endl;

	Square square2(10, 20, 30);
	//std::cout << "square.length: " << square._length << std::endl;
	std::cout << "square2.area: " << square2.getarea() << std::endl;
	std::cout << std::endl;
	*/

	std::cout << std::endl;

}

