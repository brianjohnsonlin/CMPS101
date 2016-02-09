/* heap.h
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: heap ADT header file
 */

typedef int Boolean;
#define TRUE 1
#define FALSE 0

typedef struct HeapStruct * heapHndl;

/*** Constructors-Destructors ***/
/* Makes new empty heap */
heapHndl newHeap(int maxSize);
 
/* Frees the heap
 * Pre: H has been created with newHeap/buildHeap
 */
void freeHeap(heapHndl* H);

/* NOTE: all Access functions and Manipulation procedures also have the
   precondition that H has been initialized by newHeap().
 */

/*** Access functions ***/
/* returns true if heap is full, else return false
 */
Boolean isFull(heapHndl H);

/* returns true if heap is empty, else return false */
Boolean isEmpty(heapHndl H);

/* returns the maximum value of the heap
 * Pre: !isEmpty()
 */
int maxValue(heapHndl H);

/*** Manipulation procedures ***/
/* returns true if heap is full, else return false
 * Pre: !isEmpty()
 */
void deleteMax(heapHndl H);

/* returns true if heap is full, else return false
 * Pre: !isFull()
 */
void insert(heapHndl H, int priority);

/* prints the heap */
void printHeap(heapHndl H);
