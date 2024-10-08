#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pid,i;

	if (vfork() == 0){
		for (i=0;i<=50;i+=2){
				printf("%d ",i);
		}
	}
	else{
	//	wait(0);
		for (i=1;i<=50;i+=2){
			printf("%d ",i);
		}
	}
	printf("\n");
}
