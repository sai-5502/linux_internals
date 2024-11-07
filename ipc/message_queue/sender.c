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
	int msgid;
	struct msgbuf msg;
	msgid=msgget(KEY,IPC_CREAT | 0666);
	if (msgid == -1){
		perror("msgget");
		return;
	}
	printf("The message identifier is created\n");
	msg.mtype=5;
	printf("Enter the message\n");
	scanf("%[^\n]s",msg.mtext);
	msgsnd(msgid,&msg,32,0);
	printf("The message sent\n");
}

