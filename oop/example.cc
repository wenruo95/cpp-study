#include<iostream>

class Box {
	int length, width, height;
	public:
		Box(int len, int wid, int hgh);
		~Box();
		int getVolume(void);
		Box operator+(const Box& box);
		int getlength() const {
			return length;
		}
		int getwidth() const {
			return width;
		}
		int getheight() const {
			return height;
		}
		int setlength(int len) {
			this->length = len;
		}
		int setwidth(int wid) {
			this->width = wid;
		}
		int setheight(int hgh) {
			this->height = hgh;
		}
};

Box::Box(int len, int wid, int hgh) : length(len), width(wid), height(hgh) {
	std::cout << "Box构造函数:\t" << length << "\t" << width << "\t" << height << std::endl;
}

Box::~Box() {
	std::cout << "Box析构函数:\t" << length << "\t" << width << "\t" << height << std::endl;
}

Box Box::operator+(const Box& box) {
	Box target(0, 0, 0);
	target.length = this->length + box.length;
	target.width = this->width + box.width;
	target.height = this->height + box.height;
	return target;
}

Box operator*(const Box& box1, const Box& box2) {
	Box target(0, 0, 0);
	target.setlength(box1.getlength() + box2.getlength());
	target.setwidth(box1.getwidth() + box2.getwidth());
	target.setheight(box1.getheight() + box2.getheight());
	return target;
}

int Box::getVolume(void) {
	return length * width * height;
}

int main(void) {
	Box box1(10, 20, 30);
	Box box2(40, 50, 60);
	Box box3 = box1 + box2;
	Box box4 = box1 * box2;
	std::cout << "box1:" << box1.getVolume() << std::endl;
	std::cout << "box2:" << box2.getVolume() << std::endl;
	std::cout << "box3:" << box3.getVolume() << std::endl;
	std::cout << "box4:" << box4.getVolume() << std::endl;
}
