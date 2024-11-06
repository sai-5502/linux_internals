#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	int fd=-1;
	struct stat st;
	char *src;
	if (argc != 2 ){
		printf("./a.out <input filename>\n");
		return;
	}
	fd = open(argv[1],O_RDWR | O_CREAT,0666);
	if (fd < 0){
		printf("The file opening is failed\n");
		return;
	}
	printf("The file is successfully opened\n");

	
	if (fstat(fd,&st) < 0){
		perror("fstat failed\n");
		close(fd);
		return;
	}
	src=mmap(0,st.st_size,PROT_READ,MAP_SHARED,fd,0);
	if (src == NULL){
		perror("map failed:");
		close(fd);
		return;
	}
	write(fd,"MY",sizeof("MY")-1);
	while (*src != '\0')
		printf("%c",*src++);
	printf("\n");

	munmap(src,st.st_size);
	close(fd);
	
}

