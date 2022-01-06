#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(void)
{
int fd;
if(-1==(fd=open("alphabet.txt",O_WRONLY|O_CREAT,S_IRWXU)))
{
perror("open()");
}
return EXIT_SUCCESS;
}
