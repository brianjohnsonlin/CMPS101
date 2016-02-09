# Brian Lin bjlin Due:4/4/14
# Makefile for decToBinary program
# It compiles the module and creates the intstackdr and decToBinary executables

decToBinary : decToBinary.o intstack.o
	gcc -ansi -Wall -Wextra -pedantic -o decToBinary decToBinary.o intstack.o

intstackdr : intstackdr.o intstack.o
	gcc -ansi -Wall -Wextra -pedantic -o intstackdr intstackdr.o intstack.o

intstack.o : intstack.h intstack.c
	gcc -c -ansi -Wall -Wextra -pedantic intstack.c

decToBinary.o : intstack.h decToBinary.c
	gcc -c -ansi -Wall -Wextra -pedantic decToBinary.c

intstackdr.o : intstack.h intstackdr.c
	gcc -c -ansi -Wall -Wextra -pedantic intstackdr.c

clean :
	rm intstackdr intstackdr.o intstack.o decToBinary decToBinary.o

# an old version of the makefile used the additional gcc option
# -I/usr/lang/SC1.0/ansi_include but it is not needed on my system
# we should double check that that option is not needed on the cats system
