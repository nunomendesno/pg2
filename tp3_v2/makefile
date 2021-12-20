
a.out: ex4_main.o ex3.o 1.2_Normalize.o 1.1_SplitFrase.o
	gcc ex4_main.o ex3.o 1.2_Normalize.o 1.1_SplitFrase.o

ex4_main.o: ex4_main.c ex3.h
	gcc -g ex4_main.c
	
ex3.o: ex3.c ex3.h
	gcc -c ex3.c

1.2_Normalize.o: 1.2_Normalize.c 1.2_Normalize.h
	gcc -c 1.2_Normalize.c

1.1_SplitFrase.o: 1.1_SplitFrase.c 1.1_SplitFrase.h
	gcc -c 1.1_SplitFrase.c


clear:
	rm *.o \
	a
