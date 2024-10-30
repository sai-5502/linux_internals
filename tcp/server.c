#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 1234
#define MAX 80

void func(int connfd){
	char buff[MAX];
	int n;
	for (;;){
		bzero(buff,MAX);
		recv(connfd,buff,sizeof(buff),0);
		printf("sai : %s\t\t me :",buff);
		bzero(buff,MAX);
		n=0;
		while ((buff[n++] = getchar()) != '\n')
			;
		send(connfd,buff,sizeof(buff),0);

		if (strncmp("exit",buff,4) == 0){
			printf("server Exit.....\n");
			break;
		}
	}
}


void main(){
	int sockfd,connfd,l;
	struct sockaddr_in server,client;
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if (sockfd == -1){
		perror("socket");
		return;
	}
	printf("The socket is successfully created\n");
	bzero(&server,sizeof(server));

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	server.sin_port=htons(PORT);
 
	if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("bind");
		return;
	}
	printf("socket successfully binded\n");
	
	if (listen(sockfd,5) == -1){
		perror("listen");
		return;
	}
	printf("The server is listening\n");
	l=sizeof(client);	

	connfd=accept(sockfd,(struct sockaddr *)&client,&l);
	if (connfd == -1){
		perror("accept");
		return;
	}
	printf("The server accept the client\n");

	func(connfd);
	close(sockfd);
}
	

