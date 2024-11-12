#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int shared_data=0;

void *thread1(){
	while(shared_data < 50){
		printf("In the writer thread\n");
		shared_data++;
		sleep(0.1);
	}
}

void *thread2(){
	while(shared_data < 50){
		printf("In the reader thread\n");
		printf("The shared data (%d) \n",shared_data);
		sleep(0.1);
	}
}

void main(){
	pthread_t tid[2];

	if (pthread_create(&tid[0],NULL,&thread1,NULL) != 0){
		perror("create 1 failed");
		return;
	}
	
	if (pthread_create(&tid[1],NULL,&thread2,NULL) != 0){
		perror("create 2 failed");
		return;
	}
	sleep(1);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	printf("The two threads are finished successfully\n");
}
