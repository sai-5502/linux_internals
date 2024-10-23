#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void main(){
	int fd;
	char buffer[64];
	fd=open("fifo",O_RDONLY,0777);
	read(fd,buffer,64);
	printf("The message is received from the named pipe\n");
	printf("Buffer = %s\n",buffer);
	close(fd);
}
	
