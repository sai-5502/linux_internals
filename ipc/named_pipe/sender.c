#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void main(){
	int fd;
	char buffer[64];
	fd=open("fifo",O_RDWR,0777);
	printf("Enter the message:");
	scanf("%[^\n]s",buffer);
	write(fd,buffer,sizeof(buffer));
	printf("The message is send to the named pipe\n");
	close(fd);
}
	
