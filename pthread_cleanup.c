#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void cleanup(void *arg)
{
	printf("cleanup: %s\n",(char*)arg);
}
void * thr_fn1(void *arg)
{
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup,"thread1 first handle");
	pthread_cleanup_push(cleanup,"thread1 sencond handle");
	printf("thread 1 push complete\n");
	return (void*)1;
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return (void*)1;
}
void * thr_fn2(void *arg)
{
	printf("thread 2 start\n");
	pthread_cleanup_push(cleanup,"thread 2 first handle");
	pthread_cleanup_push(cleanup,"thread 2 second handle");
	printf("thread 2 push complete\n");
	pthread_exit((void*)2);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit((void*)2);
}
int main(void)
{
	int err;
	void *tret;
	pthread_t tid1, tid2;
	err = pthread_create(&tid1,NULL,thr_fn1,(void*)1);
	if(err != 0)
	{
		return 1;
	}
	err = pthread_create(&tid2,NULL,thr_fn2,(void*)1);
	if(err != 0)
	{
		return 1;
	}
	err = pthread_join(tid1,&tret);
	if(err != 0)
	{
		return 1;
	}
	printf("thred1 exit code %ld\n",(long)tret);
	err = pthread_join(tid2,&tret);
	if(err != 0)
	{
		return 1;
	}
	printf("thread2 exit code %ld\n",(long)tret);
	exit(0);

}
