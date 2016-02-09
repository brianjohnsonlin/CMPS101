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
    insertAtFront(TheList,25728);
    printf("%d\n",getFirst(TheList));
    printf("%d\n",getLast(TheList));
    /*should have same value*/
    
    printf("testing list with three numbers\n");
    insertAtFront(TheList,1589458);
    insertAtBack(TheList,357621112);
    printf("%d\n",getFirst(TheList));
    
    /*test empty in full case*/
    if(isEmpty(TheList)) printf("Empty\n");
    else printf("not Empty\n");
    
	/*test moving the current pointer around*/
    moveFirst(TheList);
    moveNext(TheList);
    printf("%d\n",getCurrent(TheList));
    moveLast(TheList);
    movePrev(TheList);
    printf("%d\n",getCurrent(TheList));
    
	/*test printList*/
    printList(out, TheList);
    
	/*test makeEmpty*/
    makeEmpty(TheList);
    if(isEmpty(TheList)) printf("Empty\n");
    else printf("not Empty\n");
    
	/*test inserting functions*/
    insertAtFront(TheList,2);
    insertAtFront(TheList,1);
    insertAtFront(TheList,4);
    insertAtBack(TheList,4);
    moveLast(TheList);
    insertBeforeCurrent(TheList,3);
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
