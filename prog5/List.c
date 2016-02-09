/* List.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: A doubly-linked list data structure ADT.
 */

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NodeStruct {
    int data;
    NodePtr next;
    NodePtr prev;
} NodeStruct;


typedef struct ListStruct {
    NodePtr first;
    NodePtr last;
    NodePtr current;
} ListStruct;


ListHndl newList(void){
    ListHndl tempList = malloc ( sizeof(ListStruct) );
    /*printf("malloc List\n");*/
    tempList->first = tempList->last = tempList->current = NULL;
    return tempList;
}

NodePtr newNode(int data){
    NodePtr tempNode = malloc(sizeof(NodeStruct));
    /*printf("malloc Node\n");*/
    tempNode->data = data;
    return tempNode;
}

void freeList (ListHndl* L){
    assert ((*L) != NULL);
    if(!isEmpty(*L)) makeEmpty(*L);
    free(*L);
    /*printf("free List\n");*/
    (*L) = NULL;
}

int isEmpty(ListHndl L){
    assert (L != NULL);
    return (L->first == NULL);
}

int offEnd(ListHndl L){
    assert (L != NULL);
    return (L->current == NULL);
}

int atFirst(ListHndl L){
    assert (L != NULL);
    return (L->first == L->current);
}

int atLast(ListHndl L){
    assert (L != NULL);
    return (L->last == L->current);
}

int getFirst(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    return L->first->data;
}

int getLast(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    return L->last->data;
}

int getCurrent(ListHndl L){
    assert(L != NULL);
    assert(!offEnd(L));
    return L->current->data;
}

void makeEmpty(ListHndl L){
    assert (L != NULL);
    while(!isEmpty(L)) deleteFirst(L);
}

void moveFirst(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    L->current = L->first;
}

void moveLast(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    L->current = L->last;
}

void movePrev(ListHndl L){
    assert(L != NULL);
    assert(!offEnd(L));
    L->current = L->current->prev;
}

void moveNext(ListHndl L){
    assert(L != NULL);
    assert(!offEnd(L));
    L->current = L->current->next;
}

void insertAtFront(ListHndl L, int data){
    NodePtr temp = newNode(data);
    assert (L != NULL);
    temp->prev = NULL;
    temp->next = L->first;
    if(!isEmpty(L)) L->first->prev = temp;
    else L->last = temp;
    L->first = temp;
}

void insertAtBack(ListHndl L, int data){
    NodePtr temp = newNode(data);
    assert(L != NULL);
    temp->next = NULL;
    temp->prev = L->last;
    if(!isEmpty(L)) L->last->next = temp;
    else L->first = temp;
    L->last = temp;
}

void insertBeforeCurrent(ListHndl L, int data){
    NodePtr temp = newNode(data);
    assert(L != NULL);
    assert(!isEmpty(L));
    if(!atFirst(L)){ /*this part doesn't need to run if current is first*/
        L->current->prev->next = temp;
        temp->prev = L->current->prev;
    }else L->first = temp;
    L->current->prev = temp;
    temp->next = L->current;
}

void deleteFirst(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    if(atFirst(L)) L->current = NULL;
    if(L->first->next == NULL){
        free(L->first);
        L->first = NULL;
        L->last = NULL;
    }else{
        L->first=L->first->next;
        free(L->first->prev);
        L->first->prev=NULL;
    }
    /*printf("free node\n");*/
}

void deleteLast(ListHndl L){
    assert(L != NULL);
    assert(!isEmpty(L));
    if(atLast(L)) L->current = NULL;
    if(L->last->prev == NULL){
        free(L->last);
        L->first = NULL;
        L->last = NULL;
    }else{
        L->last=L->last->prev;
        free(L->last->next);
        L->last->next=NULL;
    }
    /*printf("free node\n");*/
}

void deleteCurrent(ListHndl L){
    assert(L != NULL);
    assert(!offEnd(L));
    if(atFirst(L)) deleteFirst(L);
    else if(atLast(L)) deleteLast(L);
    else{
        L->current->next->prev = L->current->prev;
        L->current->prev->next = L->current->next;
        free(L->current);
        L->current = NULL;
        /*printf("free node\n");*/
    }
}

void printList(FILE* out, ListHndl L){
    NodePtr currNode = L->first;
    assert(L != NULL);
    if (out == NULL) {
        fprintf(stderr, "Can't open output file!\n");
        exit(1);
    }
    /*if(L->first!=NULL) fprintf(out, "First:   %d\n",L->first->data);
    else fprintf(out, "First:   NULL\n");
    if(L->last!=NULL) fprintf(out, "Last:    %d\n",L->last->data);
    else fprintf(out, "Last:    NULL\n");
    if(L->current!=NULL) fprintf(out, "Current: %d\n",L->current->data);
    else fprintf(out, "Current: NULL\n");*/
    fprintf(out, "List:\n");
    while(currNode != NULL){
        fprintf(out, "%d",currNode->data);
        if(currNode == L->current)fprintf(out,"*");
        fprintf(out,"\n");
        currNode = currNode->next;
    }
    fprintf(out,"\n");
}