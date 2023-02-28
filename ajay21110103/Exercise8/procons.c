#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int item=0;
#define buflen 1
int buf[buflen];
int in=0,out=0;
sem_t empty,full;
pthread_mutex_t mutex;
void produce(void *param){
	do{
	item++;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	buf[in]=item;
	
	printf("Producer Produced : %d\n",buf[in]);
	in=(in++)%buflen;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
//	sleep(1);
	}while(1);


}

void consume(void *param){
	do{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);

	printf("Consumer Consumed :%d\n",buf[out]);
	out=(out++)%buflen;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
//	sleep(1);
	}while(1);

}


int main(){
	pthread_t producer,consumer;
	sem_init (&empty,0,buflen);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&producer,NULL,(void*)produce,NULL);
	pthread_create(&consumer,NULL,(void*)consume,NULL);
	
	
	pthread_join(producer,NULL);
	pthread_join(consumer,NULL);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	
}
