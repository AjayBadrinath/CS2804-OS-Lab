#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define no_philosopher 5
#define no_chopstick 5
pthread_t philosopher[no_philosopher];
pthread_mutex_t chopstick[no_chopstick];
void eatPhil(int k){
	printf("Philosopher %d ->Thinking\n",k );
	pthread_mutex_lock(&chopstick[k]);
	pthread_mutex_lock(&chopstick[(k+1)%no_philosopher]);
	printf("Philosopher %d -> Eating\n",k);
	sleep(1);
	pthread_mutex_unlock(&chopstick[k]);
	pthread_mutex_unlock(&chopstick[(k+1)%no_philosopher]);
	printf("Philosopher %d -> Ate\n",k);
}





int  main()
{
		 
	for(int i=1;i<=no_chopstick;i++){
		pthread_mutex_init(&chopstick[i],NULL);
	}
	for(int i=1;i<=no_philosopher;i++){
		pthread_create(&philosopher[i],NULL,(void*)eatPhil,(int* )i);
	}
	for(int i=1;i<=no_philosopher;i++){
		pthread_join(philosopher[i],NULL);

	}
	for(int i=1;i<=no_chopstick;i++){
		pthread_mutex_destroy(&chopstick[i]);
	}

	return 0;
}