#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum){
	printf("caught the signal %d \n",signum);
//	exit(0);
}

void sigterm_handler(int signum){
	printf("caught the signal %d \n",signum);
//	exit(0);
}

void main(){
	printf("sigint signo = %d\n",SIGINT);
	printf("sigterm signo = %d\n",SIGTERM);
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	raise(SIGINT);
	//raise(SIGTERM);
	while(1);
}
