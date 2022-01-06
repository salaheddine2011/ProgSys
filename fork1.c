#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t a;
int i;
printf("F\n");
for(i=0;i<3;i++)
{
a=fork();
if(a==0)
{
printf("f%d\n",i+1);
break;
}
}
while(wait(0)>0);
}
