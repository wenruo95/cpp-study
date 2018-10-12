#include<iostream>
#include<pthread.h>

#define NUM_THREADS 5

/*
 * thread			执行指针标识符指针
 * attr				一个不透明的属性对象，可以用来设置指针属性.
 * start_routine	线程运行函数骑士地址，线程创建就会执行
 * arg				运行函数的参数
 *
 * pthread_create(thread, attr, start_routine, arg)
 *
 * pthread_exit(status)
 *
 * pthread_join(threadid, status)
 *
 * pthread_detach(threadid)
 */

struct thread_data {
	int thread_id;
	char *message;
};

void* say_hello(void* args) {
	std::cout << (char*)args << ":\tHelloWorld" << std::endl;
	return 0;
}

void* say_hello2(void* args) {
	struct thread_data *data;
	data = (struct thread_data *) args;
	std::cout << "ID:\t" << data->thread_id << "\tMessage:\t" << data->message << std::endl;
}

int main(void) {
	pthread_t tids[NUM_THREADS];
	struct thread_data datas[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		char str[10];
		sprintf(str, "thread_%d", i + 1);
		datas[i].thread_id = i;
		datas[i].message = str;
		//int ret = pthread_create(&tids[i], NULL, say_hello, str);
		int ret = pthread_create(&tids[i], NULL, say_hello2, (void*) &datas[i]);
		if (ret != 0) {
			std::cout << "pthread_create error: error_code=" << ret << std::endl;
		}
	}
	pthread_exit(NULL);

}