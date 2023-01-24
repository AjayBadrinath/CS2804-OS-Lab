#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
char buffer[15];
read(1,buffer,10);
printf("%s\n",buffer);
}
