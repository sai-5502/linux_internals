#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigsegv_handler(int signum){
	printf("caught the signal %d\n",signum);
//	exit(0);
}

void sigint_handler(int signum){
	printf("caught the signal %d\n",signum);
//	exit(0);
}

void main(){
	printf("the SIGSEGV signo is %d\n",SIGSEGV);
	printf("the SIGINT signo is %d\n",SIGINT);
	signal(SIGSEGV, sigsegv_handler);
	signal(SIGINT, sigint_handler);
	kill(getpid(),SIGSEGV);
	kill(getpid(),SIGINT);
	raise(SIGSEGV);
	raise(SIGINT);
	kill(getpid(),SIGKILL);
	while(1);
}
