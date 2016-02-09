/* Graphdr.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: Driver program for the Graph ADT
 */

#include "Graph.h"
#include <stdio.h>

int main(void){
    /* Emulates first test file:
     * 5 2
     * 0 3 4 1
     * 1 2 4
     * 2
     * 3
     * 4 2
     * 0 1
     * 4 1
     */
    Graph thisGraph = newGraph(5);
    addEdge(thisGraph,0,3);
    addEdge(thisGraph,0,4);
    addEdge(thisGraph,0,1);
    addEdge(thisGraph,1,2);
    addEdge(thisGraph,0,4);
    addEdge(thisGraph,4,2);
    
    doBFS(thisGraph,0);
    printf("Dist: %d\n", getDistance(thisGraph,1));
    ListHndl L = getPathTo(thisGraph,1);
    if(!isEmpty(L)){
        moveFirst(L);
        while(!offEnd(L)){
            printf("%d ", getCurrent(L));
            moveNext(L);
        }printf("\n");
    }else printf("No path\n");
    freeList(&L);
    
    doBFS(thisGraph,4);
    printf("Dist: %d\n", getDistance(thisGraph,1));
    L = getPathTo(thisGraph,1);
    if(!isEmpty(L)){
        moveFirst(L);
        while(!offEnd(L)){
            printf("%d ", getCurrent(L));
            moveNext(L);
        }printf("\n");
    }else printf("No path\n");
    freeList(&L);
    
    printf("SIZE: %d\n", getSize(thisGraph));
    printGraph(thisGraph);
    
    freeGraph(&thisGraph);
    return 0;
}