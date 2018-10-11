#include<iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp = b;
	b = a;
	a = temp;
}

template <class T>
class Stack {
	public:
		Stack();
		void push(T);
		void pop(T);
		T gettop();
		void empty();
};
