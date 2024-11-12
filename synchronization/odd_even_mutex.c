#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid[2];
unsigned int n=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
unsigned int rc;

void* even();
void* odd();

void main(){

	if (pthread_create(&tid[0],0,&even,0) != 0){
		perror("Thread 1 failed");
		return;
	}

	if (pthread_create(&tid[0],0,&odd,0) != 0){
		perror("Thread 1 failed");
		return;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	//sleep(1);
}

void* even(){
	pthread_mutex_lock(&mutex);
	do{
		if (n%2 == 0)
			printf("%d is even\n",n++);
		else
			rc=pthread_mutex_unlock(&mutex);
	}while(n<50);
}

void* odd(){
	rc=pthread_mutex_lock(&mutex);
	do{
		if (n%2 != 0)
			printf("%d is odd\n",n++);
		else
			rc=pthread_mutex_unlock(&mutex);
	}while(n<50);
}


