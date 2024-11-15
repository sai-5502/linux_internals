#include <stdio.h>
#include <sys/stat.h>

void main(int argc,char *argv[]){
	struct stat st;

	if (lstat(argv[1],&st) == -1){
		perror("lstat");
		return;
	}
	printf("The size of the file(%s) is %ld\n",argv[1],st.st_size);
}
