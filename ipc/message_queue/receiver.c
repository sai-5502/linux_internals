#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>

struct msgbuf {
	long mtype;      
        char mtext[32];      
};

#define KEY 2222

void main(){
	int msgid=-1;
	struct msgbuf msg;
	printf("The size of the key = %ld\n",sizeof(key_t));
	msgid=msgget(KEY,IPC_CREAT | 0666);
	if (msgid == -1){
		perror("msgget");
		return;
	}
	printf("The message identifier is created\n");
	msgrcv(msgid,&msg,32,0,0);
	printf("The message received\n");
	printf("message text = %s   message type = %ld\n",msg.mtext,msg.mtype);
}

