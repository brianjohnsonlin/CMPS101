/* HashTable.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: A Hash Table data structure ADT
 */

#include "HashTable.h"
#include <assert.h>
#include <tgmath.h>
#include <string.h>
#include <stdlib.h>

/* contains book name and list of library numbers */
typedef struct HashNodeStruct{
    char name[40];
    ListHndl L;
}HashNodeStruct;

/* contains library numbers */
typedef struct ListNodeStruct{
    int num;
}ListNodeStruct;

/* hash table */
typedef struct HashTableStruct{
    int tableSize;
    ListHndl* array;
} HashTableStruct;

HashTable newTable(int tableSize){
    HashTable tempTable = malloc(sizeof(HashTableStruct));
    tempTable->tableSize = tableSize;
    tempTable->array = calloc((tableSize),sizeof(ListHndl));
    for(int i = 0; i < tableSize; i++) tempTable->array[i] = newList();
    return tempTable;
}

HashNode newHashNode(char* name){
    HashNode tempNode = malloc(sizeof(HashNodeStruct));
    strcpy(tempNode->name, name);
    tempNode->L = newList();
    return tempNode;
}

void freeTable(HashTable* H){
    assert ((*H) != NULL);
    for(int i = 0; i < (*H)->tableSize; i++){
        /* free all library lists first */
        if(!isEmpty((*H)->array[i])){
            moveFirst((*H)->array[i]);
            while(!offEnd((*H)->array[i])){
                HashNode N = getCurrent((*H)->array[i]);
                ListHndl L = N->L;
                freeList(&L);
                moveNext((*H)->array[i]);
            }
        }
        
        /*and then free the slot lists*/
        freeList(&((*H)->array[i]));
    }
    free((*H)->array);
    free(*H);
    (*H) = NULL;
}

/* djb2 hash algorithm */
long hash(unsigned char* key){
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return abs(hash);
}

ListHndl lookup(HashTable H, char* key){
    assert (H != NULL);
    ListHndl slot = H->array[hash((unsigned char*)key) % H->tableSize];
    if(isEmpty(slot)) return NULL;
    else moveFirst(slot);
    while(!offEnd(slot)){
        HashNode temp = getCurrent(slot);
        if(strcmp(key,temp->name) == 0) return temp->L;
        else moveNext(slot);
    }
    return NULL;
}

int getNum(ListNode N){
    return N->num;
}

void insert(HashTable H, char* name, int num){
    assert (H != NULL);
    ListNode temp = malloc(sizeof(ListNodeStruct));
    temp->num = num;
    ListHndl L = lookup(H, name);
    /* if book does not exist, make one */
    if(L == NULL){
        ListHndl slot = H->array[hash((unsigned char*)name) % H->tableSize];
        HashNode N = newHashNode(name);
        L = N->L;
        insertAtBack(slot,N);
    }
    insertAtBack(L,temp);
}

void deleteHashNode(HashTable H, char* name){
    assert (H != NULL);
    ListHndl slot = H->array[hash((unsigned char*)name) % H->tableSize];
    if(isEmpty(slot)) return;
    moveFirst(slot);
    while(!offEnd(slot)){
        HashNode temp = getCurrent(slot);
        if(strcmp(name, temp->name) == 0){
            ListHndl L = temp->L;
            freeList(&L);
            deleteCurrent(slot);
        }else moveNext(slot);
    }
}

void deleteListNode(HashTable H, char* name, int num){
    assert (H != NULL);
    ListHndl L = lookup(H, name);
    if(L == NULL) return;
    moveFirst(L);
    while(!offEnd(L)){
        ListNode temp = getCurrent(L);
        if(temp->num == num){
            deleteCurrent(L);
            break;
        }
        moveNext(L);
    }
    /* if library list of book ends up being empty, delete the book */
    if(isEmpty(L)) deleteHashNode(H, name);
}

/* for debugging purposes*/
void printTable(HashTable H){
    assert (H != NULL);
	printf("HashTable: Size %d\n", H->tableSize);
    for(int i = 0; i < H->tableSize; i++){
        printf("%d:\n",i);
        if(isEmpty(H->array[i])) continue;
        moveFirst(H->array[i]);
        while(!offEnd(H->array[i])){
            HashNode N = getCurrent(H->array[i]);
            printf("-%s\n",N->name);
            moveFirst(N->L);
            while(!offEnd(N->L)){
                ListNode temp = getCurrent(N->L);
                printf("--%d\n",temp->num);
                moveNext(N->L);
            }
            moveNext(H->array[i]);
        }
    }
}
