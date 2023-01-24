#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	int p=fork();
	if(p>0){
		sleep(10);
		printf("Parent Process:%d\n",getpid());
//		printf("Parent Terminating");

			
	}
	else {
		printf("Child process %d\n Parent Pid:%d\n",getpid(),getppid());
		sleep(30);
		exit(0);
	
	}

}
