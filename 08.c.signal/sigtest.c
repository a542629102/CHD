#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
void func_ctrl_z();
kill(pid, signal);
int main()
{
	int counter;
	pid_t pid;
	(void) signal(SIGTSTP, func_ctrl_z);
	(void) signal(SIGTSTP, SIG_IGN);//ignore SIGTSTP
	(void) signal(SIGTSTP, SIG_DFL);//restore SIGTSTP default proc
	pid = fork();
	if(pid<0)
	{
		perror("fork failed.\n");
		exit(-1);
	}
	else if(pid==0)
 	{
		while(1)
		{
			counter++;
			printf("running %ds\n", counter);
			sleep(1);
		}
		exit(0);
	}
	else
	{
		sleep(10);
		signal(pid, SIGKILL);
	}
	return 0;
}
void func_ctrl_z()
{
	printf("I don't want hangup.\n");
}
