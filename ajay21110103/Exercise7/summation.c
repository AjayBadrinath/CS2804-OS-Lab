#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int s;
#define N 5
pthread_t n[N];
pthread_mutex_t msum;
int a[10];
int sum=0;
void* summation(void* param){
	long tid=(long)param;
	int s,e,tsum;
	s=(int)tid*2;
	e=s+2;
	for(int i=s;i<e;i++){
		tsum+=a[i];
	}
	pthread_mutex_lock(&msum);
	sum+=tsum;
	pthread_mutex_unlock(&msum);
	pthread_exit(0);

}
void main(){
	//a={1,2,3,4,5,6,7,8,9,10};
	for(int i=1;i<=10;i++){
		a[i-1]=i;
	}
	pthread_attr_t attr;
	pthread_mutex_init(&msum,NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	for(int i=0;i<N;i++){
		pthread_create(&n[i],&attr,summation,(void*)i);
	}
	pthread_attr_destroy(&attr);
	for(int i=0;i<N;i++){
		pthread_join(n[i],NULL);
	}
	printf("%d",sum);
	pthread_mutex_destroy(&msum);
	pthread_exit(0);

}
