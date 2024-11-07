#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

#define PORT 1234
#define MAX 80

void func(int sockfd,struct sockaddr_in client){
	int n,l;
	char buffer[MAX];
	while(1){
		bzero(buffer,MAX);
		l=sizeof(client);
		recvfrom(sockfd,buffer,MAX,0,
				(struct sockaddr *)&client,&l);
		printf("From client = %s\n",buffer);
		bzero(buffer,MAX);
		printf("To client :");
		n=0;
		while ((buffer[n++]=getchar()) != '\n')
			;
		sendto(sockfd,buffer,sizeof(buffer),0,
			(struct sockaddr *)&client,sizeof(client));

		if (strncmp(buffer,"exit",4) == 0){
			printf("server EXITS .....\n");
			break;
		}
	}
}

void main(){
	int sockfd;

	struct sockaddr_in server,client;

	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if (sockfd == -1){
	       perror("socket");
       	       return;
	}
	printf("The socket is successfully created\n");
	
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("bind");
		return;
	}
	printf("The socket is successfully binded to the given ip and port\n");
	
	func(sockfd,client);
//	buffer[n]='\0';
	
	close(sockfd);

}
