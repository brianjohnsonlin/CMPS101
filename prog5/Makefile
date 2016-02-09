# Makefile
# Yunyi Ding yding13@ucsc.edu
# Brian Lin bjlin@ucsc.edu
# Description: The Makefile for the Graph ADT and the gps program.
 
all : Listdr Graphdr gps
	
gps : gps.o Graph.o
	gcc -ansi -Wall -Wextra -pedantic -o gps gps.o Graph.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o
	
Graphdr : Graphdr.o Graph.o
	gcc -ansi -Wall -Wextra -pedantic -o Graphdr Graphdr.o Graph.o List.o

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 List.c

Graph.o : Graph.h Graph.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 Graph.c
	
Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 Listdr.c

Graphdr.o : Graph.h Graphdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 Graphdr.c

gps.o : Graph.h gps.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 gps.c
	
clean :
	rm Listdr Listdr.o List.o Graphdr Graphdr.o Graph.o gps.o gps
