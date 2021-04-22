myText: main.o, LinkedList.o
	gcc -ansi -Wall -g main.o LinkedList.o -o myText
main.o: main.c myText.h
	gcc -c -ansi -g -Wall main.c -o main.o
LinkedList.o: LinkedList.c myText.h
	gcc -c -ansi -g -Wall LinkedList.c -o LinkedList.o
