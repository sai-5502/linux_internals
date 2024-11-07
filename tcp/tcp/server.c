#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX 80

void func(int clifd){
	char buffer[MAX];
	int n;
	
	while(1){
		bzero(buffer,MAX);
		if (recv(clifd,buffer,sizeof(buffer),0) == -1){
			perror("recv");
			return;
		}
		printf("from client : %s ",buffer);
		bzero(buffer,MAX);
		printf("\t\tto server : ");
		n=0;
		while ((buffer[n++]=getchar()) != '\n')
			;
		if (send(clifd,buffer,sizeof(buffer),0) == -1){
			perror("send");
			return;
		}
	}
}

void main(){
	int sockfd,clifd,l;
	struct sockaddr_in server,client;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if (sockfd == -1){
		perror("socket");
		return;
	}
	printf("The socket is successfully created\n");
	bzero(&server,sizeof(server));

	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("bind");
		return;
	}
	printf("The socket is successfully binded\n");

	if (listen(sockfd,5) == -1){
		perror("listen");
		return;
	}
	printf("The listening successfully\n");
	l=sizeof(client);

	clifd=accept(sockfd,(struct sockaddr *)&client,&l);
	if (clifd == -1){
		perror("accept");
		return;
	}
	printf("The socket accept the client\n");

	func(clifd);

	close(sockfd);
}
