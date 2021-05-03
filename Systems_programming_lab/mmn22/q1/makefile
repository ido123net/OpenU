myset.exe: myset.o set.o set.h
	gcc -ansi -Wall -g myset.o set.o -o myset.exe
set.o: set.c set.h
	gcc -c -ansi -Wall -g set.c -o set.o
myset.o: myset.c set.h
	gcc -c -ansi -Wall -g myset.c -o myset.o
