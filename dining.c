#include<stdio.h>
#include<stdlib.h>

#include<pthread.h>
#include<semaphore.h>

#define N 5


sem_t chopstic[N];
pthread_t phi[N];

void *start(void *k)
	{
	int i=(int*)k;
	while(1)
		{
		printf("Philosopher %d is Hungry\n",i+1);
		
		sem_wait(&chopstic[i]);
		sem_wait(&chopstic[(i+1)%N]);

		printf("Philosopher %d is Eating\n",i+1);
		sleep(2);

		sem_post(&chopstic[i]);
		sem_post(&chopstic[(i+1)%N]);
		
		printf("Philosopher %d is Thinking\n",i+1);
		sleep(2);
		}
	}

int main()
	{
	int i;
	for(i=0;i<N;i++)
		sem_init(&chopstic[i],0,1);
	for(i=0;i<N;i++)
		pthread_create(&phi[i],NULL,start,(void*)i);
	
	for(i=0;i<N;i++)
		pthread_join(phi[i],NULL);	
	
	return 0;
	}
