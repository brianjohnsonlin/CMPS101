/* insertionSort.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: insertionSort algorithm
 */

void insertionSort(int keys[], int numKeys){
    if(numKeys == 0) return;
    for(int i = 1; i < numKeys; i++){
        int place = i;
        for(int j = 0; j < i; j++){
            if(keys[i] < keys[j]){
                place=j;
                break;
            }
        }
        if(place != i){
            int temp = keys[i];
            for(int j = i; j > place; j--) keys[j] = keys[j-1];
            keys[place] = temp;
        }
    }
}
