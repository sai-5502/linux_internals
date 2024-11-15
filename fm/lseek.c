#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	int fd;
	int pos;

	fd=open(argv[1],O_RDONLY,0666);

	if (fd == -1){
		perror("open");
		return;
	}
	printf("The file(%s) is opened successfully\n",argv[1]);

	pos=lseek(fd,0,SEEK_SET);
	printf("The position of the file = %d\n",pos);


	pos=lseek(fd,5,SEEK_SET);
	printf("The position of the file = %d\n",pos);

	pos=lseek(fd,0,SEEK_END);
	printf("The position of the file = %d\n",pos);

	pos=lseek(fd,-5,SEEK_END);
	printf("The position of the file = %d\n",pos);

	close (fd);
}
