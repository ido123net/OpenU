myset: myset.o set.o input_handler.o set.h input_handler.h
	gcc -ansi -Wall -g myset.o set.o input_handler.o -o myset
set.o: set.c set.h
	gcc -c -ansi -Wall -g set.c -o set.o
myset.o: myset.c set.h
	gcc -c -ansi -Wall -g myset.c -o myset.o
input_handler.o: input_handler.c input_handler.h
	gcc -c -ansi -Wall -g input_handler.c -o input_handler.o
