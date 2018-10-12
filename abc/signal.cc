#include<iostream>
#include<csignal>
#include<unistd.h>

/*
 * SIGABRT		程序的异常终止
 * SIGFPE		错误的算术运算
 * SIGILL		检测非法指令
 * SIGINT		检测到交互注意信号
 * SIGSEGV		非法访问内存 
 * SIGTERM		发送到程序的终止请求
 */
/*
 * void (*signal (int sig, void(*func)(int))) (int);
 * 函数接收两个参数，第一个是整数代表信号的编号，第二个指向一个信号处理函数的指针
 */


void signalHandler(int signum) {
	std::cout << "Interrupt signnal (" << signum << ") received.\n" << std::endl;
	exit(signum);
}

int main(void) {
	int i = 0;
	signal(SIGINT, signalHandler);
	while (++i) {
		std::cout << i++ << "\tGoing to sleep......" << std::endl;
		if (i > 5) {
			raise(SIGINT);
		}
		sleep(1);
	}
	return 0;
}
