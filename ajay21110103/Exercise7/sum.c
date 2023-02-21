#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int s;
void *  sum(void * param){
	int * arr=param;
	s=1;
	for(int i=0;i<9;i++){
		s*=arr[i];

	}
	pthread_exit(0);
}
int main(){
pthread_t p[2];
int arr[]={1,2,3,4,5,6,7,8,9};
for (int i=0;i<2;i++){
	pthread_create(&p[i],NULL,sum,arr);
	if (i%2==0) sleep(1);
}

//pthread_create(&p2,NULL,sum,arr);
pthread_join(p[0],NULL);
pthread_join(p[1],NULL);
printf("%d",s);

}
