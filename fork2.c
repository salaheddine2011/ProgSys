#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t a,b,c,d;
int i;
for(i=0;i<3;i++)
 {
a=fork();
if(a==0)
{printf("f%d\n",i+1);
if(i==1)
{b=fork();
if(b==0)
{ printf("f%d.1\n",i+1);
c=fork();
if(c==0)
{
printf("f%d1.1\n",i+1);
}
}
}
if(i==2)
{ d=fork();
if(d==0)
{printf("f%d.1\n",i+1);
}
}
break;
}
}
while(wait(0)>0);
}



