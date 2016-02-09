# Makefile
# Yunyi Ding yding13@ucsc.edu
# Brian Lin bjlin@ucsc.edu
# Description: The Makefile for the HashTable ADT and the library program.
 
all : Listdr HashTabledr library
	
library : library.o HashTable.o
	gcc -ansi -Wall -Wextra -pedantic -o library library.o HashTable.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o
	
HashTabledr : HashTabledr.o HashTable.o
	gcc -ansi -Wall -Wextra -pedantic -o HashTabledr HashTabledr.o HashTable.o List.o

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 List.c

HashTable.o : HashTable.h HashTable.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 HashTable.c
	
Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 Listdr.c

HashTabledr.o : HashTable.h HashTabledr.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 HashTabledr.c

library.o : HashTable.h library.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 library.c
	
clean :
	rm Listdr Listdr.o List.o HashTabledr HashTabledr.o HashTable.o library.o library
