/* sortPrint.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: Driver and test file for sorting algorithms
 */

#include "heapSort.h"
#include "insertionSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *in;
    FILE *outInst;
    FILE *outHeap;
    char origName[128];
    char modName[128];
    
    /* greeting & prompt for input and output file names */
    printf("Welcome! Please enter your .in input file here: ");
    scanf("%s",origName);
    strcpy(modName,origName);
    strcat(modName,".in");
    in = fopen(modName, "r");
    if(in == NULL){
        printf("Error: This input file does not exist.\n");
        exit(1);
    }
    strcpy(modName,origName);
    strcat(modName,".outInst");
    outInst = fopen(modName, "w");
    strcpy(modName,origName);
    strcat(modName,".outHeap");
    outHeap = fopen(modName, "w");
    
    /* scan in the numbers*/
    int numKeys;
    fscanf(in,"%d", &numKeys);
    int* keysI = calloc((numKeys),sizeof(int));
    int* keysH = calloc((numKeys),sizeof(int));
    printf("Scanning in numbers from file... \n");
    for(int i = 0; i < numKeys; i++){
        fscanf(in, "%d", &(keysI[i]));
        keysH[i]=keysI[i];
    }
    printf("Done.\n");
    
    /* sort */
    printf("Sorting with Insertion Sort... \n");
    insertionSort(keysI, numKeys);
    printf("Done.\nSorting with Heap Sort... \n");
    heapSort(keysH, numKeys);
    printf("Done.\n");
    
    /* verify and output sort */
    int wrong = 0;
    printf("Verifying Sort for Insertion Sort... \n");
    for(int i = 0; i < numKeys-1; i++) if(keysI[i] > keysI[i+1]){wrong=1;break;}
    if(wrong == 1) printf("Missort found.\n");
    else printf("Done.\n");
    wrong = 0;
    printf("Verifying Sort for Heap Sort... \n");
    for(int i = 0; i < numKeys-1; i++) if(keysH[i] > keysH[i+1]){wrong=1;break;}
    if(wrong == 1) printf("Missort found.\n");
    else printf("Done.\n");
    
    /* output */
    printf("Writing array to output files... \n");
    fprintf(outInst, "%d\n", numKeys);
    fprintf(outHeap, "%d\n", numKeys);
    for(int i = 0; i < numKeys; i++){
        fprintf(outInst, "%d\n", keysI[i]);
        fprintf(outHeap, "%d\n", keysH[i]);
    }
    printf("Done.\n");
    
    /* free everythinggggggggggggggggggggg */
    free(keysI);
    free(keysH);
    fclose(in);
    fclose(outInst);
    fclose(outHeap);
    
    return 0;
}
