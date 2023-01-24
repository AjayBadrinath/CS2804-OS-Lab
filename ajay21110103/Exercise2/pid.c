#include <unistd.h>
#include <stdio.h>
int main(){
if(fork()==0){
printf("Parent pid: %d\n ",getpid());
printf("Child pid: %d\n",getppid());
}

}
