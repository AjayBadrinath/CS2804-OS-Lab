#include <unistd.h>
int main(){
char* path="/bin/ls";
char* arg[]={path,"-la",NULL};
execl(path,"-la",NULL);
execv(path,arg);
}
