#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 64

void main(int argc,char *argv[]){
	int nread,fd;
	char buffer[SIZE]={0};
	fd = open(argv[1],O_RDONLY,777);
	while (nread=read(fd,buffer,SIZE) != 0){
		write(0,buffer,sizeof(buffer));
	}
	close(fd);

}
