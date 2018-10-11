#include<iostream>

class Shape {
	protected:
		int width, height;
	public:
		Shape(int wid = 0, int hgh = 0) : width(wid), height(hgh) {
			std::cout << "Shape 构造函数:" << width << "\t" << height << std::endl;
		}

		virtual int area() {
			std::cout << "Parent class Area:";
			return 0;
		}
};

class Rectangle : public Shape {
	public:
		Rectangle(int wid = 0, int hgh = 0) : Shape(wid, hgh) {
			std::cout << "Rectangle 构造函数:" << width << "\t" << height << std::endl;
		}

		int area() {
			std::cout << "Rectangle class Area:";
			return width * height;
		}
};

class Triangle : public Shape {
	public:
		Triangle(int wid = 0, int hgh = 0): Shape(wid, hgh) {
			std::cout << "Triangle 构造函数:" << width << "\t" << height << std::endl;
		}
		int area() {
			std::cout << "Triangle class Area:";
			return width * height / 2;
		}
};

int main(void) {
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);
	Triangle tri2(11);

	shape = &rec;
	std::cout << shape->area() << std::endl;

	shape = &tri;
	std::cout << shape->area() << std::endl;

	std::cout << tri2.area() << std::endl;
}
