/* sortComp.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: Driver program to compare insertion sort and heap sort speeds
 */

#include <stdio.h> /* printf */
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */
#include "heapSort.h"
#include "insertionSort.h"
#include <stdlib.h>
#include <string.h>

int main(void){
    clock_t startTime, duration;
    FILE *in;
    char origName[128];
    char modName[128];
    
    /* read your data and initialize array of unsorted keys */
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
    
    /* run the sorting algorithm */
    startTime = clock();
    printf("Sorting with Insertion Sort... \n");
    insertionSort(keysI, numKeys);
    printf("Done. ");
    duration = clock() - startTime;
  printf("Insertion Sort took %f seconds.\n",((float)duration )/CLOCKS_PER_SEC);
    
    startTime = clock();
    printf("Sorting with Heap Sort... \n");
    heapSort(keysH, numKeys);
    printf("Done. ");
    duration = clock() - startTime;
    printf("Heap Sort took %f seconds.\n",((float)duration )/CLOCKS_PER_SEC);
    
    /* free everythinggggggggggggggggggggg */
    free(keysI);
    free(keysH);
    fclose(in);
    
    return 0;
}
