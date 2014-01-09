#include<stdio.h>

#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>


sem_t wrt,mutex;
char data='@';
int rdcnt=0;

void *write(void *tid)
	{
	int id=(int*)tid;

	while(1)
		{
		sem_wait(&wrt);
		data++;
		printf("Writer %d writes %c",id,data);
		sleep(2);
		sem_post(&wrt);
		}
	}
void *read(void *tid)
	{
	int id=(int*)tid;

	while(1)
		{
		sem_wait(&mutex);
		rdcnt++;
		if(rdcnt==1)
			sem_wait(&wrt);
		sem_post(&mutex);
		printf("Reader %d reads %c",id,data);
		sleep(1);
		
		sem_wait(&mutex);
		rdcnt--;
		if(rdcnt==0)
			sem_post(&wrt);
		sem_post(&mutex);

		}
	}

int main()
	{
	int i;

	pthread_t rd[3],wr[2];


	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);

	for(i=0;i<3;i++)
		pthread_create(&rd[i],NULL,read,(void*)i);

	//for(i=0;i<2;i++)
          //      pthread_create(&wr[i],NULL,write,(void*)i);

	for(i=0;i<3;i++)
		pthread_join(rd[i],NULL);

	// for(i=0;i<2;i++)
          //      pthread_join(wr[i],NULL);


	return 0;

	}
