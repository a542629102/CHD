#include <stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
int main()
{
int i, rfd,wfd,len=0,fd_in;
char str[32];
int flag,stdinflag;
fd_set write_fd,read_fd;
struct timeval net_timer;
wfd =open("fifotest1",O_WRONLY);
rfd = open( "fifotest2",O_RDONLY);
if(rfd<=0||wfd<=0)return 0;
while(1)
{
FD_ZERO(&read_fd);
FD_SET(rfd,&read_fd);
FD_SET(fileno(stdin),&read_fd);
net_timer.tv_sec=5;
net_timer.tv_usec=0;
memset(str,0,sizeof(str));
if(i=select(rfd+1, &read_fd,NULL, NULL, &net_timer) <= 0)
    continue;
if(FD_ISSET(rfd,&read_fd))
{
  read(rfd,str,sizeof(str));
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("%s\n",str);
}
if(FD_ISSET(fileno(stdin),&read_fd))
{
printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
fgets(str,sizeof(str),stdin);
len=write(wfd,str,strlen(str));
}
}
close(rfd);
close(wfd);
}
