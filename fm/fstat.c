#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	int fd;
	struct stat st;
	fd=open(argv[1],O_RDONLY,0666);
	
	if (fstat(fd,&st) == -1){
		perror("fstat");
		return;
	}
	printf("The size of the file(%s) is %ld\n",argv[1],st.st_size);
}
