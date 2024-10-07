#include <stdio.h>
#include <unistd.h>

void main(){
	int n;
	fork();
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	printf("enter the number\n");
	scanf("%d",&n);
}

