#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(){
	int pipefd[2];
	pid_t pid;
	char buffer[64]={0};
	
	if (pipe(pipefd) == -1){
		perror("pipe fail:");
		return;
	}

	pid=fork();
	if (pid < 0){
		printf("child creation is failed\n");
		return;
	}
	else if(pid == 0){//The child process is processing
		read(pipefd[0],buffer,64);
		//printf("%s\n",buffer);
		write(1,"Buffer = ",strlen("Buffer = "));
		write(1,buffer,strlen(buffer));
		write(1,"\n",1);
	}
	else{//The parent process is processing
	     write(pipefd[1],"umasaisankar",strlen("umasaisankar"));
	}

}
