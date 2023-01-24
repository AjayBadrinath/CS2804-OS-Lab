#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <unistd.h>
int main(){
	char buf[10];
	char* SendShm="Sender";
	int shmFD;
	shmFD=shm_open(SendShm,O_RDONLY,0666);
	void* ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shmFD,0);
	printf("%s",(char*)ptr);
	//read(shmFD,buf,10);
	//write(1,buf,10);
	shm_unlink("Sender");

}
