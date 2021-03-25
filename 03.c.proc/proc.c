#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t i,j;
	printf("I am parent:%d\n",getpid());
	i=fork();
	if (i != 0)
	{
		printf("I'm parent:%d my parent:%d\n",getpid(),getppid());	
		wait(NULL);
	}
	else 
	{
		printf("I'm child:%d my parent:%d\n",getpid(),getppid());
		 for(j=0; j<100;j++)
                {
                        printf(".");
			fflush(stdout);
                        sleep(1);
                }
	}
	return 0;
}
