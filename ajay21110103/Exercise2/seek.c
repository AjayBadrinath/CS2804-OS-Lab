
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
int buf[40];
int fd=open("test.txt",O_RDWR);
read(fd,buf,40);
write(1,buf,40);
lseek(fd,15,SEEK_SET);
write(1,"\n",1);
read(fd,buf,40);
write(1,buf,40);


}



