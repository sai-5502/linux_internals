#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void main(){
	DIR *dir=NULL;
	struct dirent *di;
	dir=opendir(".");
	int n=1;
	while ((di=readdir(dir)) != NULL){
		printf("file name = %s\tfile type = %d\n",di->d_name,di->d_type);
	}
	closedir(dir);
}
