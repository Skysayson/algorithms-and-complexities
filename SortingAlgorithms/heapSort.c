#include "header.h"
#include <stdio.h>
#define MAX 10

int main() {
    int inputVal[MAX] = {5,2,4,76,22,3,4,5,6,90}, x;

    Array heap;
    initHeap(&heap);

    for(x = 0; x < MAX; x++) {
        heap.elems[x] = inputVal[x];
        heap.lastIndx++;
    }
    
    printf("UNORDERED TREE: ");
    for(x = 0; x < MAX; x++) {
        printf("%d ", heap.elems[x]);
    }
    printf("\n");

    heapify(&heap);

    printf("AFTER HEAPIFY: ");
    for(x = 0; x < MAX; x++) {
        printf("%d ", heap.elems[x]);
    }
    printf("\n");


    heapSort(&heap);

    printf("AFTER HEAPSORT: ");
    for(x = 0; x < MAX; x++) {
        printf("%d ", heap.elems[x]);
    }
    printf("\n");


    return 0;
}