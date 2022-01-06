#include<stdio.h>
#include<memory.h>
#include<unistd.h>
int main(int argc,char**argv)
{
char buffer[BUFSIZ+1];
int fd[2],w,r;
pipe(fd);
w=write(fd[1],"hello world",strlen("hello world"));
r=read(fd[0],buffer,BUFSIZ);
printf("%s",buffer);
}
