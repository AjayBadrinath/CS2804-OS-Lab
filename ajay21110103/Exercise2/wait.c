#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	int status;
	if(fork()==0)
	{
	printf("Exiting..");
	exit(1);
	
	}else{
	wait(&status);
	
	}
	printf("Exit status %d",WEXITSTATUS(status));
	

}
