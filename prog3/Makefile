# Makefile
# Brian Lin bjlin@ucsc.edu
# Yunyi Ding yding13@ucsc.edu
# Description: Makefile for the heapADT, insertion and heap sort algorithms, and various driver programs
 
all : heapDriver sortComp sortPrint

heapDriver : heapDriver.o heap.o
	gcc -ansi -Wall -Wextra -pedantic heapDriver.o heap.o -o heapDriver

sortComp : sortComp.o insertionSort.o heapSort.o heap.o
	gcc -ansi -Wall -Wextra -pedantic sortComp.o insertionSort.o heapSort.o heap.o -o sortComp

sortPrint : sortPrint.o insertionSort.o heapSort.o heap.o
	gcc -ansi -Wall -Wextra -pedantic sortPrint.o insertionSort.o heapSort.o heap.o -o sortPrint

heap.o : heap.h heap.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 heap.c

heapDriver.o : heapDriver.c
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 heapDriver.c

heapSort.o : heapSort.c heapSort.h heap.o
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 heapSort.c

insertionSort.o : insertionSort.c insertionSort.h
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 insertionSort.c

sortComp.o : sortComp.c insertionSort.o heapSort.o
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 sortComp.c

sortPrint.o : sortPrint.c insertionSort.o heapSort.o
	gcc -c -ansi -Wall -Wextra -pedantic -std=gnu99 sortPrint.c

clean :
	rm heapDriver heapDriver.o heap.o sortComp sortPrint heapSort.o insertionSort.o sortComp.o sortPrint.o
