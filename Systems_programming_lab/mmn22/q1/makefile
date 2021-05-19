input: myset.o set.o input.o set.h input.h
	gcc -ansi -Wall -g myset.o set.o input_handler.o -o input
set.o: set.c set.h
	gcc -c -ansi -Wall -g set.c -o set.o
myset.o: myset.c set.h
	gcc -c -ansi -Wall -g myset.c -o myset.o
input.o: input.c input.h
	gcc -c -ansi -Wall -g input.c -o input.o
