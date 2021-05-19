myset: set.o input.o myset.o
	gcc -ansi -Wall -g set.o input.o myset.o -o myset
myset.o: myset.c
	gcc -c -ansi -Wall -g myset.c -o myset.o
set.o: set.c set.h
	gcc -c -ansi -Wall -g set.c -o set.o
input.o: input.c input.h
	gcc -c -ansi -Wall -g input.c -o input.o
