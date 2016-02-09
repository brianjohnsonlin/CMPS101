/* library.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Program that uses the HashTable ADT to record books
 *              in libraries and find those books for customers.
 */

#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* helper function for printing invalid input*/
void invalidInput(void){
    printf("Error: Invalid input.\n");
    exit(1);
}

/* main program*/
int main(void){
    /* variables */
    char testName[128];
    char tempLine[128];
    int tableSize;
    int numCopies;
    int numRequests;
    HashTable Library;
    
    /* Greeting & prompt for test name
     * NOTE: Input files are assumed to be <test name>.lib.in
     * and <test name>.req.in and the output file <test name>.out.
     */
    printf("Welcome! Please enter the test name here: ");
    scanf("%s",testName);
    FILE* catalog = fopen(strcat(strcpy(tempLine, testName), ".lib.in"), "r");
    FILE* requests = fopen(strcat(strcpy(tempLine, testName), ".req.in"), "r");
    if(catalog == NULL || requests == NULL){
        printf("Error: Input file(s) do(es) not exist.\n");
        printf("Input files are assumed to be <test name>.lib.in and\n");
        printf("<test name>.req.in and the output file <test name>.out.\n");
        exit(1);
    }
    FILE* out = fopen(strcat(strcpy(tempLine, testName), ".out"), "w");
    
    printf("Reading in Library...\n");
    /* read in numbers of books and tableSize */
    do{
        if(fgets(tempLine, 128, catalog) == NULL) invalidInput();
    }while(strcmp(tempLine, "\n") == 0);
    if(sscanf(tempLine,"%d %d", &numCopies, &tableSize) != 2) invalidInput();
    
    /* creates new HashTable and reads in Library */
    Library = newTable(tableSize);
    for(int i = 0; i < numCopies; i++){
        /* read in whole line */
        do{
          if(fgets(tempLine, 128, catalog) == NULL){
            printf("Error: Number of books does not match (too little).\n");
            exit(1);
          }
        }while(strcmp(tempLine, "\n") == 0);
        
        /* parses libID */
        int libID;
        if(sscanf(tempLine,"%d", &libID) != 1) invalidInput();
        
        /* parses bookName */
        char bookName[40];
        int indexStart;
        for(indexStart = 1; tempLine[indexStart-1] != ' '; indexStart++)
            if(indexStart > 128) invalidInput();
        int indexEnd;
        for(indexEnd = 0; tempLine[indexStart+indexEnd] != '\n'; indexEnd++){
            if(indexEnd > 39) invalidInput();
            bookName[indexEnd] = tempLine[indexStart+indexEnd];
        }
        bookName[indexEnd] = '\0';
        
        /* insert */
        insert(Library, bookName, libID);
    }
    
    /* checks for any lingering books */
    while(fgets(tempLine, 128, catalog) != NULL){
        if(strcmp(tempLine, "\n") != 0){
            printf("Error: Number of books does not match (too many).\n");
            exit(1);
        }
    }
    
    printf("Reading in Requests...\n");
    /* read in numbers of requests */
    do{
        if(fgets(tempLine, 128, requests) == NULL) invalidInput();
    }while(strcmp(tempLine, "\n") == 0);
    if(sscanf(tempLine,"%d", &numRequests) != 1) invalidInput();
    
    /* reads in requests and writes corresponding library codes to outfile */
    for(int i = 0; i < numRequests; i++){
        /* read book request */
        do{
          if(fgets(tempLine, 128, requests) == NULL){
            printf("Error: Number of requests does not match (too little).\n");
            exit(1);
          }
        }while(strcmp(tempLine, "\n") == 0);
        for(size_t i = 0; i < strlen(tempLine); i++){
            if(tempLine[i] == '\n'){
                tempLine[i] = '\0';
                break;
            }
        }
        
        /* find book, if no book, the blank line */
        ListHndl bookList = lookup(Library, tempLine);
        if(bookList != NULL){
            moveFirst(bookList);
            while(!offEnd(bookList)){
                ListNode temp = getCurrent(bookList);
                fprintf(out, "%d", getNum(temp));
                moveNext(bookList);
                if(!offEnd(bookList)) fprintf(out, " ");
            }
        }
        fprintf(out, "\n");
    }
    
    /* checks for any lingering requests */
    while(fgets(tempLine, 128, requests) != NULL){
        if(strcmp(tempLine, "\n") != 0){
            printf("Error: Number of requests does not match (too many).\n");
            exit(1);
        }
    }
    
    /*free everythingggggggggggg*/
    freeTable(&Library);
    fclose(catalog);
    fclose(requests);
    
    /* end program */
    printf("Done.\n");
    return 0;
}
