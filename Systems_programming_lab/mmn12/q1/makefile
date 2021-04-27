myText: main.o LinkedList.o Buffer.o myText.o data.h
	gcc -ansi -Wall -g main.o LinkedList.o Buffer.o myText.o -o myText
myText.o: myText.c data.h
	gcc -c -ansi -g -Wall myText.c -o myText.o
main.o: main.c data.h
	gcc -c -ansi -g -Wall main.c -o main.o
LinkedList.o: LinkedList.c data.h
	gcc -c -ansi -g -Wall LinkedList.c -o LinkedList.o
Buffer.o: Buffer.c data.h
	gcc -c -ansi -g -Wall Buffer.c -o Buffer.o
	