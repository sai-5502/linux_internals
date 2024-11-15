#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 64

void main(int argc,char *argv[]){
	int fdin,fdout;
	int nread;
	char buffer[SIZE];

	fdin=open(argv[1],O_RDONLY,0666);
	fdout=open(argv[2],O_WRONLY | O_CREAT,0666);
	
	if (fdin == -1 | fdout == -1) {
		printf("opening the files are failed\n");
		return;
	}
	
	while (nread=read(fdin,buffer,SIZE) != 0) {
		write(fdout,buffer,sizeof(buffer));
		memset(buffer,0,SIZE);
	}
	close(fdin);
	close(fdout);


}
