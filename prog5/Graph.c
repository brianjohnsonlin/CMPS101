/* Graph.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: A Graph data structure ADT with BFS implementation
 */

#include "Graph.h"
#include <assert.h>
#include <stdlib.h>

typedef struct VertexStruct{
    ListHndl adjList;
    int dist;   /* -1 for infinity */
    int parent; /* -1 for null */
    int seen;   /* used for BFS, 0 for FALSE 1 for TRUE */
} VertexStruct;

typedef struct GraphStruct{
    int size;
    Vertex* vertices;
} GraphStruct;

Graph newGraph(int numVerts){
    Graph tempGraph = malloc(sizeof(GraphStruct));
    tempGraph->size = numVerts;
    tempGraph->vertices = calloc(numVerts,sizeof(VertexStruct));
    for(int i = 0; i < numVerts; i++){
        Vertex tempVert = malloc(sizeof(VertexStruct));
        tempVert->adjList = newList();
        tempVert->dist = -1;
        tempVert->parent = -1;
        tempVert->seen = 0;
        tempGraph->vertices[i] = tempVert;
    }
    return tempGraph;
}

void freeGraph(Graph* G){
    assert ((*G) != NULL);
    for(int i = 0; i < (*G)->size; i++){
        freeList(&((*G)->vertices[i]->adjList));
        free((*G)->vertices[i]);
    }
    free((*G)->vertices);
    free(*G);
    (*G) = NULL;
}

int getDistance(Graph G, int destination){
    assert (G != NULL);
    assert (destination < G->size);
    return G->vertices[destination]->dist;
}

ListHndl getPathTo(Graph G, int destination){
    assert (G != NULL);
    assert (destination < G->size);
    ListHndl path = newList();
    if(getDistance(G, destination) == -1) return path;
    int current = destination;
    while(current != -1){
        insertAtFront(path, current);
        current = G->vertices[current]->parent;
    }
    return path;
}

int getSize(Graph G){
    assert (G != NULL);
    return G->size;
}

void addEdge(Graph G, int from, int to){
    assert (G != NULL);
    assert (from < G->size);
    assert (to < G->size);
    insertAtBack(G->vertices[from]->adjList, to);
}

void doBFS(Graph G, int source){
    assert (G != NULL);
    assert (source < G->size);
    
    /* reset all BFS data */
    for(int i = 0; i < G->size; i++){
        G->vertices[i]->dist = -1;
        G->vertices[i]->parent = -1;
        G->vertices[i]->seen = 0;
    }
    
    /* BFS */
    ListHndl Q = newList();
    G->vertices[source]->seen = 1;
    G->vertices[source]->dist = 0;
    insertAtBack(Q, source);
    while(!isEmpty(Q)){
        int u = getFirst(Q);
        ListHndl uList = G->vertices[u]->adjList;
        if(!isEmpty(uList)){
            moveFirst(uList);
            while(!offEnd(uList)){
                Vertex v = G->vertices[getCurrent(uList)];
                if(v->seen == 0){
                    v->parent = u;
                    v->seen = 1;
                    v->dist = G->vertices[u]->dist + 1;
                    insertAtBack(Q, getCurrent(uList));
                }
                moveNext(uList);
            }
        }
        deleteFirst(Q);
    }
    freeList(&Q);
}

/* for debugging purposes*/
void printGraph(Graph G){
    assert (G != NULL);
	printf("Graph: Size %d\n", G->size);
    for(int i = 0; i < G->size; i++){
        Vertex temp = G->vertices[i];
        ListHndl tempsList = temp->adjList;
        printf("%d: adj: ",i);
        if(!isEmpty(tempsList)){
            moveFirst(tempsList);
            while(!offEnd(tempsList)){
                printf("%d ",getCurrent(tempsList));
                moveNext(tempsList);
            }
        }else printf("none ");
        printf("dist: %d parent: %d\n", temp->dist, temp->parent);
    }
}
