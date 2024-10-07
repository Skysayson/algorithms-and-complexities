#ifndef HEADER_H
#define HEADER_H
#define SIZE 51
#define INF 0xFFFF

typedef struct {
    int elems[SIZE], lastIndx;
} Array;

typedef struct node {
    int data;
    struct node* link;
} *LinkedList;

// Function Prototypes
void insertionSort(int arr[], int size);
void displayArr(int arr[], int size);
void swap(int *x, int *y);
void bubbleSort(int arr[], int size);
void combSort(int arr[], int size);
void selectionSort(int arr[], int size);
void shellSort(int arr[], int size);
void initHeap(Array *HEAP);
int parentIdx(int childIdx);
int leftChildIdx(int parentIdx);
int rightChildIdx(int parentIdx);
void heapify(Array *HEAP);
int deleteMax(Array* HEAP);
void heapSort(Array *HEAP);
void heapifySubtree(Array *HEAP, int i);
int *countingSort(int arr[], int size);
void bucketSort(int arr[], int size);
void gnomeSort(int arr[], int size);
void radixSort(int arr[], int size);


//  Tree functions


#endif