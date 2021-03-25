#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{	
	pid_t pid;
	printf("I'm load:%d\n", getpid());
	pid= fork();
	if (pid == 0)
	{
	execl("/home/chd/prog/03.c.proc/proc","proc",NULL);
	}
	else
		{
		printf("I'm load, I finished\n");
		wait(NULL);
		}
	return 0;
}
