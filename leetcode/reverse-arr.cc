#include<iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	//int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size / 2; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
	for (int i = 0; i < size; i++) {
		std::cout << i << "\t" << arr[i] << std::endl;
	}
}
