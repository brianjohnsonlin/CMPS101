# Makefile
# Yunyi Ding yding13@ucsc.edu
# Brian Lin bjlin@ucsc.edu
# Description: The Makefile for the List ADT and the store program.
 
all : Listdr store

store : store.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o store store.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 List.c

Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 Listdr.c

store.o : List.h store.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 store.c

clean :
	rm Listdr Listdr.o List.o store.o store
