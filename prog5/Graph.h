/* Graph.h
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: header file for the Graph ADT
 */

#include "List.h"

/* define the graph and vertex structures */
typedef struct VertexStruct * Vertex;
typedef struct GraphStruct * Graph;

/*** Constructors-Destructors ***/
Graph newGraph(int vertNum);
void freeGraph(Graph* G); /* Pre: G has been created with newGraph.*/

/* NOTE: all Access functions and Manipulation procedures that have
 * Graph G as a parameter also have the precondition that G has
 * been initialized by newGraph().
 */

/*** Access functions ***/
/* returns distance from source to destination
 * will return -1 if there is no path or BFS has not been run
 * Pre: destination < size
 */
int getDistance(Graph G, int destination);

/* returns a list of integers detailing a path on the graph
 * will return an empty list if there is no path
 * Pre: destination < size
 */
ListHndl getPathTo(Graph G, int destination);

/* returns the number of vertices in G */
int getSize(Graph G);

/*** Manipulation procedures ***/
/* adds "to" to "from"'s adjacency list
 * Pre: to and from are both < size
 */
void addEdge(Graph G, int from, int to);

/* Remaps all parents and distances based on BSF from source
 * Pre: source < size
 */
void doBFS(Graph G, int source);

/*** Other functions ***/
/* prints a list of vertices, their adjacency
 * lists, parent vertex, and distance
 */
void printGraph(Graph G);
