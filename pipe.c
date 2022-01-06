#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int pfd1[2],pfd2[2];

int pere(){
  close(pfd1[1]);
  dup2(pfd1[0],0);
  close(pfd1[0]);
  execlp("cut","cut","-d",":","-f1,3,4,7",(char *)0);
  printf("cut failed");

  return 0;
}


int fils(){
  close(pfd1[0]);
  dup2(pfd1[1],1);
  close(pfd1[1]);
  pipe(pfd2);
  switch(fork()){
  case -1:
        perror("fork"); 
	exit(1);
  case 0 :
        pfils();
  default :

  close(pfd2[1]);
  dup2(pfd2[0],0);
  close(pfd2[0]);


  	execlp("grep","grep","root",(char *)0);
  	printf("grep failed");
  	return 3;
  }
}

int pfils(){
  close(pfd2[0]);
  dup2(pfd2[1],1);
  close(pfd2[1]);
  execlp("cat","cat","/etc/passwd",(char *)0);
  printf("cat failed");
  return 2;
}


int main(){

  pipe(pfd1);
  
  switch(fork()){
	  case -1 : 
	  	perror("fork"); 
	  	exit(1);
	  case 0 : 
	  	fils();
	  default : 
	   	pere();
  }
  
  return EXIT_SUCCESS;

}