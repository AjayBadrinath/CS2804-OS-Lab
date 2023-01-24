#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
//#include <stdio.h>
int main(){
int k=open("test.txt",O_RDONLY);
char buffer[100];
read(k,buffer,100);
write(1,buffer,100);
}
