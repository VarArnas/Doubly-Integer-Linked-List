main.exe: main.o DoublyLinkedList.o UI.o
	gcc -std=c99 -o main.exe main.o DoublyLinkedList.o UI.o

main.o: main.c
	gcc -std=c99 -c main.c

DoublyLinkedList.o: DoublyLinkedList.c DoublyLinkedList.h
	gcc -std=c99 -c DoublyLinkedList.c

UI.o: UI.c DoublyLinkedList.h
	gcc -std=c99 -c UI.c