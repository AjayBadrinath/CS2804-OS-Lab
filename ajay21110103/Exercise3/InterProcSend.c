#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
//typedef struct values{
//	char* something;
//	int val;
//}val;


int main(){
char* SharedMemName="Sender";
char* message="Hi There!!\n";

int shmFD;
void* ptr;
shmFD=shm_open(SharedMemName,O_CREAT|O_RDWR,0666);
if(shmFD==-1){
	write(1,"[+][shm_open]Failed To Create Shared Memory",40);
	return -1;
}
ftruncate(shmFD,4096);
ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shmFD,0);
sprintf(ptr,"%s",message);
ptr+=strlen(message);
}
