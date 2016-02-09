/* List.h
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Header file for List.c.
 */
 
 #include <stdio.h>

/* define the node and list structures */
typedef struct NodeStruct * NodePtr;
typedef struct ListStruct * ListHndl;

/*** Constructors-Destructors ***/
ListHndl newList( void );
void freeList(ListHndl* L); /* Pre: L has been created with newList.*/

/* NOTE: all Access functions and Manipulation procedures also have the
   precondition that L has been initialized by newList().
 */

/*** Access functions ***/
int isEmpty(ListHndl L);    /* returns true is list is empty else returns false.*/
int offEnd(ListHndl L);     /* returns true is current == NULL*/
int atFirst(ListHndl L);    /* returns true if current == first and !offEnd()*/
int atLast(ListHndl L);     /* returns true if current == last and !offEnd()*/
void* getFirst(ListHndl L);  /* return the first element; pre: !isEmpty()*/
void* getLast(ListHndl L);   /* return the last element; pre: !isEmpty()*/
void* getCurrent(ListHndl L);/* return the current element pre: !offEnd()*/

/*** Manipulation procedures ***/
void makeEmpty(ListHndl L); /* delete all elements from the list,
                            // making it empty. Post: isEmpty(), offEnd() are both true*/
void moveFirst(ListHndl L); /* without changing list order, make the first element
                            // the current one. Pre: !isEmpty(); Post: !offEnd()*/
void moveLast(ListHndl L);  /* without changing list order, make the last element
                            // the current one. Pre: !isEmpty(); Post: !offEnd()*/
void movePrev(ListHndl L);  /* move the current marker one element earlier in the list
                            // Pre: !offEnd(); Post: offEnd() only if atFirst() was true*/
void moveNext(ListHndl L);  /* move the current marker one element later in the list.
                            // Pre: !offEnd(); Post: offEnd() only if atLast() was true*/
void insertAtFront(ListHndl L, void* data); /* Inserts new element before first
                            // Post: !isEmpty(); doesn’t change current element*/
void insertAtBack(ListHndl L, void* data); /* Inserts new element after last one
                            // Post: !isEmpty(); doesn’t change current element*/
void insertBeforeCurrent(ListHndl L, void* data); /* Inserts new element before current one
                            // Pre: !offEnd(); Post: !isEmpty(), !offEnd(), !atFirst()*/
void deleteFirst(ListHndl L); /* delete the first element. Pre: !isEmpty()*/
void deleteLast(ListHndl L); /* delete the last element. Pre: !isEmpty()*/
void deleteCurrent(ListHndl L); /* delete the current element.
                            // Pre: !isEmpty(), !offEnd(); Post: offEnd()*/

/*** Other operations ***/
void printList(FILE* out, ListHndl L); /* prints out the list with the
                            // current element marked, helpful for debugging*/
