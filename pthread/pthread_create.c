#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void *thread1(){
	int n=10;
	printf("The thread1 id = %d\n",getpid());
	printf("In the thread process n address = %p and n value = %d\n",&n,n);
	printf("The thread1 id = %ld\n",pthread_self());
	while(1){
		sleep(1);
	}
}

void main(){
	pthread_t tid;
	int n=5;
	printf("In the main process thread id = %d\n",getpid());

	if (pthread_create(&tid,NULL,&thread1,NULL) != 0){
		perror("pthread create");
		return;
	}

	printf("The main thread id = %ld\n",pthread_self());
	if (pthread_setname_np(tid,"mythread_sai") != 0){
		perror("pthread_setname_np");
		return;
	}

	printf("The thread id = %ld\n",tid);
	pthread_join(tid,NULL);
	while(n){
		printf("In the main process n adddress = %p and n value = %d\n",&n,n--);
	}
	while(1){
		sleep(1);
	}
}
