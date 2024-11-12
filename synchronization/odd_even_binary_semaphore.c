#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include  <semaphore.h>

sem_t even,odd;
int n=0;

void *even_no(){
	while(n<50){
		sem_wait(&even);
		printf("%d is even\n",n++);
		sem_post(&odd);
	}
}

void *odd_no(){
	while(n<50){
		sem_wait(&odd);
		printf("%d is odd\n",n++);
		sem_post(&even);
	}
}

void main(){
	pthread_t tid[2];
	sem_init(&even,0,1);
	sem_init(&odd,0,0);

	if (pthread_create(&tid[0],0,&even_no,0) != 0){
			perror("even thread fails");
			return;
	}
	if (pthread_create(&tid[0],0,&odd_no,0) != 0){
			perror("even thread fails");
			return;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	sleep(1);
}
