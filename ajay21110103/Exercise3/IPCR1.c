#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
typedef struct ts{
	char* something;
	int value;
}t_s;
int main(){

t_s* test_struct=shmat(0,NULL,0);
printf("%s\n%d\n",test_struct->something,test_struct->value);


}
