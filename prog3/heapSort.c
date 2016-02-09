/* heapSort.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: heapSort algorithm
 */

#include "heap.h"

void heapSort(int keys[], int numKeys){
    if(numKeys == 0) return;
    heapHndl H = newHeap(numKeys);
    for(int i = 0; i < numKeys; i++) insert(H, keys[i]);
    for(int i = numKeys-1; i > -1; i--){
        keys[i] = maxValue(H);
        deleteMax(H);
    }
    freeHeap(&H);
}
