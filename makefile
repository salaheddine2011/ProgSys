excute: useComplexe.o complexe.o
	gcc -Wall  useComplexe.o complexe.o -o excute -lm
useComplexe.o : useComplexe.c complexe.h
	gcc -Wall -c useComplexe.c
complexe.o : complexe.c complexe.h
	gcc -Wall -c complexe.c
