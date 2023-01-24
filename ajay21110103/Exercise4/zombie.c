#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
pid_t pid=fork();
printf("PID CHILD %d",getpid());
if(pid>0){
sleep(34);

}else{
exit(0);
}

}
