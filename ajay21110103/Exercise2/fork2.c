#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
printf("Current processid: %d",(int)getpid());
pid_t a=fork();
printf(" After fork :%d\n",(int)a);
if(a<0){
fprintf(stderr,"Error \n");

}
else if (a==0){
printf("Child Process Created\n");
}
else{
printf("Forking not done yet\n");
wait(NULL);
printf("Child created\n");
}

}
