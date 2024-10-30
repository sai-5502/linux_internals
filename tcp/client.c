#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 1234
#define MAX 80

void func(int sockfd){
	char buff[MAX];
	int n;
	for (;;){
		bzero(buff,sizeof(buff));
		printf("\t\tme :");
		n=0;
		while ((buff[n++] = getchar()) != '\n')
			;
		send(sockfd,buff,sizeof(buff),0);
		bzero(buff,sizeof(buff));
		recv(sockfd,buff,sizeof(buff),0);
		printf("sai : %s",buff);
		
		if (strncmp("exit",buff,4) == 0){
			printf("client Exit.....\n");
			break;
		}
	}
}


void main(){
	int sockfd,connfd;
	struct sockaddr_in server,client;
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if (sockfd == -1){
		perror("socket");
		return;
	}
	printf("The socket is successfully created\n");
	bzero(&server,sizeof(server));

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(PORT);
 
	if (connect(sockfd,(struct sockaddr*)&server,sizeof(server)) == -1){
		perror("connected");
		return;
	}
	printf("The socket is successfully connected to the server\n");
	
	func(sockfd);
	close(sockfd);
}
	

