#include <stdio.h>
#include <sys/stat.h>

void main(int argc,char *argv[]){
	struct stat st;
	if (stat(argv[1],&st) == -1){
		printf("failed\n");
		return;
	}
	printf("The size of the file(%s) is %ld\n",argv[1],st.st_size);

}
