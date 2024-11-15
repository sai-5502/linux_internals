#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	int fd;
	char *buffer="Hello World!";
	fd=open(argv[1],O_WRONLY | O_CREAT,0666);
	write(fd,buffer,strlen(buffer));
	write(fd,"\n",1);
	close(fd);

}
