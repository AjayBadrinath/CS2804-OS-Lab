#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(){

	char* write1=(char*)malloc(sizeof(char)*30);
	char* read1=(char*) malloc(sizeof(char)*30);
	pid_t pid;
	int fd[2];
	write1= "Hello World!!!";
	if(pipe(fd)==0){
		pid=fork();
		printf("Parent pid:%d\n",getppid());
		if(pid>0){
			printf("Child process created :%d\n",getpid());
			close(fd[0]);
			write(fd[1],write1,strlen(write1)+1);
			printf("Sent From %d to %d\n",getppid(),getpid());
			close(fd[1]);
		}
		else{
			close(fd[1]);
			read(fd[0],read1,30);
			printf("Read %s from %d\n",read1,getpid());
			close(fd[0]);
		}
	}
}
