#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
typedef struct
{
	char name[4];
	int age;
}people;
int main(int argc,char** argv)
{
	int shm_id,i;
	key_t key;
	char temp;
	people *p_map;
	char* name="/home/chd/prog/05.c.tongxin/1";
	key = ftok(name,0);
	shm_id=shmget(key,4096,IPC_CREAT);
	if(shm_id==-1)
	{
		perror("获取出错");
		return -1;
	}
	p_map=(people*)shmat(shm_id,NULL,0);
	temp='a';
	for(i=0;i<10;i++)
	{
		temp+=1;
		memcpy((*(p_map+i)).name,&temp,1);
		(*(p_map+i)).age=20+i;
	}
	if(shmdt(p_map)==-1)
		perror("解除映射错误");
		return 0;
}
