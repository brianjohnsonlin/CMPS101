/* store.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Program that uses the List ADT to record
 * 				purchases of books from customers.
 */

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* helper function for printing invalid input*/
void invalidInput(void){
    printf("Error: Invalid input.\n");
    exit(1);
}

/* main program*/
int main(){
	/* variables */
    char inName[128];
    char outName[128];
    ListHndl array[128];
    char tempLine[128];
    int customers;
    int purchases;
    int tempCust;
    unsigned long tempBook;
    FILE *in;
    FILE *out;
    
	/* greeting & prompt for input and output file names */
    printf("Welcome! Please enter your input file here: ");
    scanf("%s",inName);
    in = fopen(inName, "r");
    if(in == NULL){
        printf("Error: This input file does not exist.\n");
        exit(1);
    }
    printf("Please enter your output file here: ");
    scanf("%s",outName);
    out = fopen(outName, "w");
    
	/* check numbers of customer and purchased */
    do{
        if(fgets(tempLine, 128, in) == NULL) invalidInput();
    }while(strcmp(tempLine, "\n") == 0);
    if(sscanf(tempLine,"%d", &customers) != 1) invalidInput();
    do{
        if(fgets(tempLine, 128, in) == NULL) invalidInput();
    }while(strcmp(tempLine, "\n") == 0);
    if(sscanf(tempLine,"%d", &purchases) != 1) invalidInput();
    
    /*makes empty Lists and fills them up*/
    for(int i = 0; i<customers; i++) array[i] = newList();
    for(int i = 0; i<purchases; i++){
        do{
          if(fgets(tempLine, 128, in) == NULL){
            printf("Error: Number of purchases does not match (too little).\n");
            exit(1);
          }
        }while(strcmp(tempLine, "\n") == 0);
        if(sscanf(tempLine,"%d", &tempCust) != 1) invalidInput();
        if(sscanf(tempLine,"%*d%lu", &tempBook) != 1) invalidInput();
        if(tempCust > customers){
            printf("Error: Invalid customer number.\n");
            exit(1);
        }
        if(isEmpty(array[tempCust-1])){
            insertAtBack(array[tempCust-1],tempBook);
            continue;
        }
        moveFirst(array[tempCust-1]);
        while(!offEnd(array[tempCust-1])){
            if(tempBook < (unsigned)getCurrent(array[tempCust-1])){
                insertBeforeCurrent(array[tempCust-1], tempBook);
                break;
            }
            moveNext(array[tempCust-1]);
        }
        if(offEnd(array[tempCust-1])) insertAtBack(array[tempCust-1],tempBook);
    }
    
	/* checks for any lingering purchases */
    for(;;){
        if(fgets(tempLine, 128, in) == NULL) break;
        if(sscanf(tempLine,"%d", &tempCust) != 0){
            printf("Error: Number of purchases does not match (too many).\n");
            exit(1);
        }
    }
    
    /*printing store*/
    fprintf(out, "customer#   books purchased\n");
    for(int i = 0; i<customers; i++){
        fprintf(out, "%d   ",i+1);
        moveFirst(array[i]);
        while(!offEnd(array[i])){
            fprintf(out, "%lu ", getCurrent(array[i]));
            moveNext(array[i]);
        }
        fprintf(out, "\n");
    }
    
    /*free everythingggggggggggg*/
    for(int i = 0; i<customers; i++) freeList(&array[i]);
    fclose(in);
    fclose(out);
    
	/* end program */
    printf("Done.\n");
    return 0;
}
