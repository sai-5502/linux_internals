#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	pid_t pid;
	printf("the process id = %d\n",getpid());
	pid=vfork();
	if (pid < 0)
		printf("the child process  creation is failed\n");
	else if (pid == 0){
		printf("in the child process %d\n",getpid());
	}
	else{
		printf("in the parent process %d\n",getpid());
	}
}
