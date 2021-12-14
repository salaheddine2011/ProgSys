
****************complexe.c****************
#include <math.h>
#include "complexe.h"
Complexe nouveauComplexe(double r,double i)
{
Complexe z;
z.re=r; z.im=i;
return z;
}
Complexe plus(Complexe z1,Complexe z2){
return nouveauComplexe(z1.re+z2.re,z1.im+z2.im);
}
Complexe moins(Complexe z1,Complexe z2){
return nouveauComplexe(z1.re-z2.re,z1.im-z2.im);
}
double module(Complexe z){
return sqrt(z.re*z.re + z.im*z.im);
}
double argument(Complexe z){
return atan( z.im / z.re);
}
*****************************************
**************complexe.h*******************
typedef struct {
double re;double im;} Complexe;
Complexe nouveauComplexe(double r,double i);
Complexe plus(Complexe z1,Complexe z2);
Complexe moins(Complexe z1,Complexe z2);
double module(Complexe z);
double argument(Complexe z);
*******************************************
************main.c**************

#include <stdlib.h>
#include <stdio.h>
#include "complexe.h"
int main() {
Complexe z1,z2,z3;
z1=nouveauComplexe(1.,0.);
z2=nouveauComplexe(0., 1.);
z3=plus(z1,z2);
printf("bonjour");
printf("Module de z3: %f\n",module (z3));
printf("Argument de z3: %f\n",argument (z3));
return EXIT_SUCCESS;
}
**********************makefile****************
usecomplexe : main.o complexe.o
	gcc -Wall main.o complexe.o -o usecomplexe -lm
usecomplexe.o: main.c complex.h
	gcc -Wall -c complexe.c
complexe.o : complexe.c complexe.h
	gcc -Wall -c complexe.c
****************************************
OBJETS=inversion.o tabio.o
CC=gcc
CFLAGS=-Wall -g
inversion : $(OBJETS)
      $(CC) $(CFLAGS) $(OBJETS)\
      -o inversion
inversion.o : inversion.c tabio.h
      $(CC) $(CFLAGS) -c iversion.c
tabio.o : tabio.c tabio.h
      $(CC) $(CFLAGS) -c tabio.c
******************************************
all:$(APPLI) clean
$(APPLI) :$(APPLI).o tabio.o
      gcc -Wall $(APPLI).o\
      tabio.o -o $(APPLI)
$(APPLI).o : $(APPLI).c tabio.h
      gcc -Wall -c tabio.c
clean : $(APPLI)
      rm -f *.o
