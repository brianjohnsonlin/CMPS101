/* Listdr.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Driver program for testing the List ADT.
 */

#include "List.h"
#include <stdio.h>

int main(){
	/*make list and output file*/
    ListHndl TheList = newList();
    FILE *out = fopen("out.out", "w");
    
    /*test empty in empty case*/
    if(isEmpty(TheList)) printf("Empty\n");
    else printf("not Empty\n");
    printf("testing insert one number\n");
    insertAtFront(TheList,(unsigned long*)25728);
    printf("%lu\n",(unsigned long)getFirst(TheList));
    printf("%lu\n",(unsigned long)getLast(TheList));
    /*should have same value*/
    
    printf("testing list with three numbers\n");
    insertAtFront(TheList,(unsigned long*)1589458);
    insertAtBack(TheList,(unsigned long*)35762111234);
    printf("%lu\n",(unsigned long)getFirst(TheList));
    
    /*test empty in full case*/
    if(isEmpty(TheList)) printf("Empty\n");
    else printf("not Empty\n");
    
	/*test moving the current pointer around*/
    moveFirst(TheList);
    moveNext(TheList);
    printf("%lu\n",(unsigned long)getCurrent(TheList));
    moveLast(TheList);
    movePrev(TheList);
    printf("%lu\n",(unsigned long)getCurrent(TheList));
    
	/*test printList*/
    printList(out, TheList);
    
	/*test makeEmpty*/
    makeEmpty(TheList);
    if(isEmpty(TheList)) printf("Empty\n");
    else printf("not Empty\n");
    
	/*test inserting functions*/
    insertAtFront(TheList,(unsigned long*)2);
    insertAtFront(TheList,(unsigned long*)1);
    insertAtFront(TheList,(unsigned long*)4);
    insertAtBack(TheList,(unsigned long*)4);
    moveLast(TheList);
    insertBeforeCurrent(TheList,(unsigned long*)3);
    printList(out,TheList);
    deleteFirst(TheList);
    deleteCurrent(TheList);
    deleteLast(TheList);
    printList(out,TheList);
    
    makeEmpty(TheList);
    printList(out,TheList);
    
	/*free list and close output file*/
    freeList(&TheList);
    fclose(out);
    return 0;
}

