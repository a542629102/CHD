#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mylock;
int g_var;
void * pthread1(void * arg)
{
	int i;
	for (i = 0; i<10;i++)
	{
		pthread_mutex_lock(&mylock);
		g_var++;
		printf("th1:%d\n",g_var);
		pthread_mutex_unlock(&mylock);
		sleep(1);
	}
	return NULL;
}
void * pthread2(void * arg)
{
        int i;
        for (i = 0; i<10;i++)
        {
                pthread_mutex_lock(&mylock);
                g_var--;
                printf("th2:%d\n",g_var);
                pthread_mutex_unlock(&mylock);
		sleep(1);
        }
        return NULL;
}
int main()
{
	pthread_t tid1,tid2;
	pthread_mutex_init(&mylock,NULL);
	pthread_create(&tid1,NULL,pthread1,NULL);
	pthread_create(&tid2,NULL,pthread2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&mylock,NULL);
	return 0;

}

