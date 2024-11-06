#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

void main(int argc,char *argv[]){
	int fdin,fdout;
	char *src,*des;
	struct stat st;
	if ((fdin=open(argv[1],O_RDONLY,0666)) < 0){
		printf("The input file opening is failed\n");
		close(fdin);
		return;
	}
	if ((fdout=open(argv[2],O_RDWR | O_CREAT,0666)) < 0){
		printf("The output file opening is failed\n");
		return;
	}

	if (fstat(fdin,&st) < 0){
		perror("fstat:");
		close(fdin);
		close(fdout);
		return;
	}

 	off_t lseek(int fd, off_t offset, int whence);
	
	if (lseek(fdout,st.st_size-1,SEEK_SET) < 0){
		perror("lseek:");
		close(fdin);
		close(fdout);
		return;
	}

	if (write(fdout,"",1) < 0){
		perror("write:");
		close(fdin);
		close(fdout);
		return;
	}

	src=mmap(0,st.st_size,PROT_READ,MAP_SHARED,fdin,0);
	if (src == NULL){
	        perror("src:");
		close(fdin);
		close(fdout);
		return;
	}

	des=mmap(0,st.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fdout,0);
	if (des == NULL){
	        perror("src:");
		munmap(src,st.st_size);
		close(fdin);
		close(fdout);
		return;
	}

	memcpy(des,src,st.st_size);
	munmap(src,st.st_size);
	close(fdin);
	close(fdout);
}
       			       





