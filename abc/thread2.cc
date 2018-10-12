#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>

#define NUM_THREADS 5

void* wait(void *arg) {
	long tid = (long) arg;
	sleep(1);

	std::cout << "Sleeping in thread " << std::endl;
	std::cout << "Thread with id :" << tid << " ...exiting" << std::endl;
	pthread_exit(NULL);
}

int main(void) {
	pthread_attr_t attr;
	pthread_t threads[NUM_THREADS];

	// 初始化并设置为可连接的 joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (int i = 0; i < NUM_THREADS; i++) {
		std::cout << "main(): creating thread," << i << std::endl;
		int rc = pthread_create(&threads[i], NULL, wait, (void*) &i);
		if (rc) {
			std::cout << "Error: unable to create thread," << rc << std::endl;
			exit(-1);
		}
	}

	// 删除属性，并等待其它线程 
	pthread_attr_destroy(&attr);

	for (int i = 0; i < NUM_THREADS; i++) {
		void* status;
		int rc = pthread_join(threads[i], &status);
		if (rc) {
			std::cout << "Error: unable to join thread," << rc << std::endl;
			exit(-1);
		}
		std::cout << "Main: complete thread id :" << i;
		std::cout << "   exiting with status :" << status << std::endl;
	}
	std::cout << "Main program exiting." << std::endl;
	pthread_exit(NULL);

}
