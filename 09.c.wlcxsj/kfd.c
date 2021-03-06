#include<stdio.h>
#include<netdb.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#define SERVPORT 12306
#define MAXDATASIZE 100
int main(int argc,char *argv[]){
	int sockfd,recvbytes,client_fd;
	char buf[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if(argc<2){
		fprintf(stderr,"Please enter the server's hostname!\n");
		exit(1);
	}
	if((host = gethostbyname(argv[1]))==NULL){
		perror("gethostbyname error!");
		exit(1);
	}
	if((sockfd = socket(AF_INET, SOCK_STREAM,0))==-1){
		perror("socket create error!");
		exit(1);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERVPORT);
	serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero),8);
	if(connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1){
		perror("connect error!");
		exit(1);
	}
	if((recvbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1){
		perror("connect error!");
		exit(1);
	}
	buf[recvbytes] = '\0';
	printf("get:%s",buf);
	close(sockfd);
       if(send(client_fd,"chenhongda \n",26,0)==-1)
                        perror("send 出错！");
                        close(client_fd);
                        exit(0);

        }



