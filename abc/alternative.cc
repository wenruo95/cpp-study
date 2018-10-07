#include<iostream>

// 交替输出a1 b1数组
int main(void) {
	char a1[] = {'1', '2', '3'};
	char b1[] = {'A', 'B', 'C', 'D'};
	int asize = sizeof(a1) / sizeof(a1[0]);
	int bsize = sizeof(b1) / sizeof(b1[0]);
	int k = 0;
	for (int i = 0; i < bsize; i++) {
		std::cout << b1[i] << "\t" << a1[k] << "\t";
		k = (k == asize - 1) ? 0 : k + 1;
	}
	std::cout << std::endl;

}
