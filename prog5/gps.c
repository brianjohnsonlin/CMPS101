/* gps.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Program that uses the Graph ADT to find paths
 *              and distances from one node to another.
 */

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* main program*/
int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        // open file and read in numVerts and numQueries
        FILE* in = fopen(argv[i], "r");
        int numVerts, numQueries;
        char tempLine[1024];
        fgets(tempLine, 1024, in);
        sscanf(tempLine, "%d %d", &numVerts, &numQueries);
        
        // read in and make graph
        Graph Map = newGraph(numVerts);
        for(int i = 0; i < numVerts; i++){
            fgets(tempLine, 1024, in);
            int vert = atoi(strtok(tempLine, " "));
            char *tempTo = strtok(NULL, " ");
            while(tempTo != NULL){
                addEdge(Map, vert, atoi(tempTo));
                tempTo = strtok(NULL, " ");
            }
        }
        
        // process queries
        for(int i = 0; i < numQueries; i++){
            int from, to;
            fscanf(in, "%d %d", &from, &to);
            doBFS(Map, from);
            if(getDistance(Map, to) == -1)
                printf("No path from %d to %d exists.\n\n", from, to);
            else{
                printf("The shortest path from %d to %d requires %d edges: \n",
                       from, to, getDistance(Map, to));
                ListHndl L = getPathTo(Map, to);
                moveFirst(L);
                while(!atLast(L)){
                    printf("%d -> ", getCurrent(L));
                    moveNext(L);
                }
                printf("%d \n\n", getCurrent(L));
                freeList(&L);
            }
        }
    
        /*free everythingggggggggggg*/
        freeGraph(&Map);
        fclose(in);
    }
    
    /* end program */
    return 0;
}
