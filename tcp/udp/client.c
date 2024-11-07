#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1234
#define MAX 80

void func(int sockfd,struct sockaddr_in server){
	char buffer[MAX];
	int l,n;
	while(1){
		bzero(buffer,MAX);
		printf("To server :");
		n=0;
		while ((buffer[n++]=getchar()) != '\n')
			;
		sendto(sockfd,buffer,sizeof(buffer),0,
			(struct sockaddr *)&server,sizeof(server));
		bzero(buffer,MAX);
	
		l=sizeof(server);
		recvfrom(sockfd,buffer,MAX,0,
			(struct sockaddr *)&server,&l);
		printf("From server = %s\n",buffer);
		
		if (strncmp(buffer,"exit",4) == 0){
			printf("client EXITS .....\n");
			break;
		}
	}
}

void main(){
	int sockfd;
	int n,l;
	
	struct sockaddr_in server,client;

	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if (sockfd == -1){
	       perror("socket");
       	       return;
	}
	printf("The socket is successfully created\n");
	
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("connect");
		return;
	}
	printf("The socket is successfully connected to the server\n");

	func(sockfd,server);

	
	close(sockfd);

}
