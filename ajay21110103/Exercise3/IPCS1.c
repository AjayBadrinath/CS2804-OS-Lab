#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/shm.h>
typedef struct test_shm{
	char* something;
	int value;

}t_s;

int main(){
key_t key=1234;
int id=shmget(key,1024,IPC_CREAT|0644);
printf("Shared Memory ID:%d",id);
t_s*ptr=shmat(id,NULL,0);
t_s *entry;
entry=(t_s*)malloc(sizeof(t_s));
entry->something="hi";
entry->value=29;
memcpy(ptr,entry,sizeof(t_s));

printf("%s\n%d\n",ptr->something,ptr->value);

}
