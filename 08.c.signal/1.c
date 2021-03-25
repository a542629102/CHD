#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
int main()
{
	int i;
	sigset_t set,pendset;
	struct sigaction action;
	(void)signal(SIGINT,fun_ctrl_c);
	if(sigemptyset(&set)<0)
		perror("初始化信号集合错误");
	if(sigaddset(&set,SIGINT)<0)
		perror("加入信号集错误");
	if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
		perror("往信号阻塞集增加一个信号集合错误");
	else
	{
		for(i=0;i<5;i++)
		{
			printf("显示此文字，表示程序处于阻塞信号状态！\n");
			sleep(2);
		}
	}
	if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
		perror("从信号阻塞集删除一个信号集合错误");
}
void fun_ctrl_c()
{
	printf("\t你按了Ctrl+C 系统是不是不理你？\n");
	printf("\t信号处理函数");
	printf("\t此例不当 结束");
	(void) signal(SIGINT,SIG_DFL);
}
