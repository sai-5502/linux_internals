#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signum){
	printf("caught the signal %d\n",signum);
}

void main(){
	printf("The SIGINT signo is %d\n",SIGINT);
	signal(SIGINT, sigint_handler);
//	signal(SIGINT, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	while(1);
}
