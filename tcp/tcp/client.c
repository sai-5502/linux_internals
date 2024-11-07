#include <stdio.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 8080
#define MAX 80

void func(int sockfd){
	char buffer[MAX];
	int n;
	
	while(1){
		bzero(buffer,MAX);
		printf("\t\tto server : ");
		n=0;
		while ((buffer[n++]=getchar()) != '\n')
			;
		if (send(sockfd,buffer,sizeof(buffer),0) == -1){
			perror("send");
			return;
		}
		bzero(buffer,MAX);
		if (recv(sockfd,buffer,sizeof(buffer),0) == -1){
			perror("recv");
			return;
		}
		printf("from server : %s ",buffer);
	}
}

void main(){
	int sockfd;
	struct sockaddr_in server;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if (sockfd == -1){
		perror("socket");
		return;
	}
	printf("The socket is successfully created\n");
	bzero(&server,sizeof(server));
	
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("connect");
		return;
	}
	printf("The client is successsfully connected to the server\n");

	func(sockfd);
	
	close(sockfd);

}
