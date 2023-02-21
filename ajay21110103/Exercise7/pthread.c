#include <stdio.h>
#include <pthread.h>
void * runner(void *arg){
	printf("ThreadRunning\n");
	return NULL;
}

int main(){
	pthread_t t1;
	printf("Call thread\n");
	pthread_create(&t1,NULL,runner,NULL);
	pthread_join(t1,NULL);
	return 0;
}
