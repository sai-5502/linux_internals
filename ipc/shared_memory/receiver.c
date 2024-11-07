#include <stdio.h>
#include <sys/shm.h>

#define KEY 2222

void main(){
	int shmid;
	char *shmaddr=NULL;
	shmid=shmget(KEY,256,IPC_CREAT | 0666);
	if (shmid == -1){
		perror("shmget");
		return;
	}
	printf("The shared memory id is created\n");

	shmaddr=shmat(shmid,NULL,0);
	if (shmaddr == NULL){
		perror("shmat");
		return;
	}
	printf("The message is received from the shared memory\n");
	printf("message = %s\n",shmaddr);
	shmdt(shmaddr);
}
