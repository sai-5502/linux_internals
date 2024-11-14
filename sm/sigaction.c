#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigaction_handler(int signum){
	switch(signum){
		case SIGINT:printf("caught the signal %d\n",signum);break;	
		case SIGTERM :printf("caught the signal %d\n",signum);break;	
		case SIGSEGV :printf("caught the signal %d\n",signum);break;	
		case SIGKILL :printf("caught the signal %d\n",signum);break;	
		case SIGABRT :printf("caught the signal %d\n",signum);break;	
	}
}

void main(){
	int ret;
	struct sigaction sa;
	sa.sa_handler=sigaction_handler;
	ret=sigaction(SIGSEGV,&sa,NULL);
	if (ret == 0)
		printf("sigaction call is success\n");
	else
		printf("sigaction call is failed = %d\n",ret);
	raise(SIGSEGV);
	
	ret=sigaction(SIGABRT,&sa,NULL);
	if (ret == 0)
		printf("sigaction call is success\n");
	else
		printf("sigaction call is failed = %d\n",ret);
	kill(getpid(),SIGABRT);
	
	ret=sigaction(SIGINT,&sa,NULL);
	if (ret == 0)
		printf("sigaction call is success\n");
	else
		printf("sigaction call is failed = %d\n",ret);
	raise(SIGINT);
	
	ret=sigaction(SIGTERM,&sa,NULL);
	if (ret == 0)
		printf("sigaction call is success\n");
	else
		printf("sigaction call is failed = %d\n",ret);
	kill(getpid(),SIGTERM);
	
	ret=sigaction(SIGKILL,&sa,NULL);
	if (ret == 0)
		printf("sigaction call is success\n");
	else
		printf("sigaction call is failed = %d\n",ret);
	raise(SIGKILL);
	while(1);
}
