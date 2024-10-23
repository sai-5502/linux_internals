#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#define NAMED_PIPE "fifo"

void main(){
	
	if (mkfifo(NAMED_PIPE,0777) == -1){
		perror("mkfifo:");
		return;
	}
	printf("The named pipe (%s) creation is success\n",NAMED_PIPE);
}

