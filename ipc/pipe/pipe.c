#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(){
	int fd[2];
	int n,i;
	char str[20];
	char buffer[64];
	pid_t pid;

	if (pipe(fd) == -1){
	       perror("pipe failed:");
       	       return;
	}	       
	pid=fork();
	if (pid < 0){//fork is failed
		perror("fork");
	}
	else if (pid == 0){//child process
		for (i=0;i<n;i++){
			memset(buffer,0,64);
		  	read(fd[0],buffer,64);
			write(1,"Buffer = ",strlen("Buffer = "));
			write(1,buffer,strlen(buffer));
			write(1,"\n",1);
		}
	}
	else{//parent process
	     	printf("enter the no .of string:\n");
		scanf("%d",&n);
		for (i=0;i<n;i++){
			scanf("%s",str);
			write(fd[1],str,strlen(str));	
		}
	}
}


