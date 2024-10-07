#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX 10

// Helper Functions-----------------------------------------------------
void displayArr(int arr[], int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%d ", arr[x]);
    }
    printf("\n\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// Helper Functions-----------------------------------------------------

// Sorting Functions----------------------------------------------------
void bubbleSort(int arr[], int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (arr[x] < arr[y])
            {
                swap(&arr[x], &arr[y]);
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    int x, y, SmallIdx = 0;
    for (x = 0; x < size - 1; x++)
    {
        SmallIdx = x;
        for (y = x + 1; y < size; y++)
        {
            if (arr[SmallIdx] > arr[y])
            {
                SmallIdx = y;
            }
        }
        swap(&arr[x], &arr[SmallIdx]);
    }
}

void tournamentSort(int arr[], int size)
{
}

void combSort(int arr[], int size)
{
    int x, gap = size, swapped = 0;

    while (gap > 1 || !swapped)
    {
        gap /= 1.3;
        for (x = 0; x + gap < size; x++)
        {
            if (arr[x] > arr[x + gap])
            {
                swap(&arr[x], &arr[x + gap]);
                swapped = 1;
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    int x, y, temp;
    for (x = 0; x < size; x++)
    {
        for (y = x - 1; y >= 0; y--)
        {
            if (arr[y] > arr[y + 1])
            {
                swap(&arr[y], &arr[y + 1]);
            }
        }
    }
}

void shellSort(int arr[], int size)
{
    int gap, x, y;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (x = 0; x < size - gap; x++)
        {
            for (y = x + gap; y >= gap; y -= gap)
            {
                if (arr[x] < arr[y - gap])
                {
                    swap(&arr[x], &arr[y]);
                }
            }
        }
    }
}

// void shellSort(int arr[], int size)
// {
//     int gap,x,y;
//     for(gap = size/2; gap > 0; gap/=2) {
//         for(x = gap; x < size; x++) {
//             int temp = arr[x];
//             for(y = x; y >= gap && arr[y-gap] > temp; y-=gap) {
//                 arr[y]=arr[y-gap];
//             }
//             arr[y]=temp;
//         }
//     }
// }
// Sorting Functions----------------------------------------------------

// Tree Functions-------------------------------------------------------

void initHeap(Array *HEAP)
{
    HEAP->lastIndx = -1;
}

int parentIdx(int childIdx)
{
    return (childIdx - 1) / 2;
}

int leftChildIdx(int parentIdx)
{
    return (2 * parentIdx) + 1;
}

int rightChildIdx(int parentIdx)
{
    return (2 * parentIdx) + 2;
}

void heapify(Array *HEAP)
{
    // Start from the last non-leaf node and heapify upwards
    for (int i = (HEAP->lastIndx / 2); i >= 0; i--)
    {
        int largest = i;              // Initialize largest as root
        int left = leftChildIdx(i);   // Left child index
        int right = rightChildIdx(i); // Right child index

        // Check if the left child exists and is greater than the root
        if (left <= HEAP->lastIndx && HEAP->elems[left] > HEAP->elems[largest])
        {
            largest = left;
        }

        // Check if the right child exists and is greater than the largest so far
        if (right <= HEAP->lastIndx && HEAP->elems[right] > HEAP->elems[largest])
        {
            largest = right;
        }

        // If the largest is not the root, swap and continue heapifying
        if (largest != i)
        {
            // Swap the root with the largest child
            int temp = HEAP->elems[i];
            HEAP->elems[i] = HEAP->elems[largest];
            HEAP->elems[largest] = temp;

            // Continue heapifying the affected subtree
            heapifySubtree(HEAP, largest);
        }
    }
}

// Helper function to heapify a subtree rooted at index i
void heapifySubtree(Array *HEAP, int i)
{
    int largest = i;
    int left = leftChildIdx(i);
    int right = rightChildIdx(i);

    // Check if the left child exists and is greater than the root
    if (left <= HEAP->lastIndx && HEAP->elems[left] > HEAP->elems[largest])
    {
        largest = left;
    }

    // Check if the right child exists and is greater than the largest so far
    if (right <= HEAP->lastIndx && HEAP->elems[right] > HEAP->elems[largest])
    {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest > i)
    {
        // Swap the root with the largest child
        int temp = HEAP->elems[i];
        HEAP->elems[i] = HEAP->elems[largest];
        HEAP->elems[largest] = temp;

        // Continue heapifying the affected subtree
        heapifySubtree(HEAP, largest);
    }
}

int deleteMax(Array *HEAP)
{
    // Check if the heap is empty
    if (HEAP->lastIndx < 0)
    {
        printf("Heap is empty!\n");
        return -1; // or some error value
    }

    // Store the maximum value (the root of the heap)
    int maxValue = HEAP->elems[0];

    // Move the last element to the root
    HEAP->elems[0] = HEAP->elems[HEAP->lastIndx--];

    // If there are still elements in the heap, heapify the root
    if (HEAP->lastIndx >= 0)
    {
        heapify(HEAP); // Ensure the entire heap satisfies the max-heap property
    }

    // Return the removed maximum value
    return maxValue;
}

void heapSort(Array *HEAP)
{
    int origLastIdx = HEAP->lastIndx;
    while (HEAP->lastIndx > 0)
    {
        HEAP->elems[HEAP->lastIndx] = deleteMax(HEAP);
    }
    HEAP->lastIndx = origLastIdx;
}

// Sort in original input array implementation
// void countingSort(int arr[], int size)
// {
//     int y, x, max = 0;
//     int *countArr;
//     for (x = 0; x < size; x++) {
//         if (arr[x] > max) {
//             max = arr[x];
//         }
//     }

//     countArr = calloc(max + 1, sizeof(int));

//     for (x = 0; x < size; x++) {
//         countArr[arr[x]]++;
//     }

//     int index = 0;
//     for (y = 0; y <= max; y++) {
//         while (countArr[y] > 0) {
//             arr[index] = y;
//             index++;
//             countArr[y]--;
//         }
//     }
// }

// Add prefix implementation
int *countingSort(int arr[], int size)
{
    int x, y, max = 0;

    // find max
    for (x = 0; x < size; x++)
    {
        if (arr[x] > max)
        {
            max = arr[x];
        }
    }

    // init countArray and output array
    int *countArr = calloc(max + 1, sizeof(int));

    for (x = 0; x < size; x++)
    {
        countArr[arr[x]]++;
    }

    for (x = 1; x <= max; x++)
    {
        countArr[x] += countArr[x - 1];
    }

    int *outputArr = calloc(size, sizeof(int));
    for (x = size - 1; x >= 0; x--)
    {
        int elem = arr[x];
        outputArr[countArr[elem] - 1] = elem;
        countArr[elem]--;
    }

    free(countArr);

    return outputArr;
}

void bucketSort(int arr[], int size)
{
    int x, max, min;
    max = min = arr[0];
    for (x = 1; x < size; x++)
    {
        if (arr[x] > max)
        {
            max = arr[x];
        }
        if (arr[x] < min)
        {
            min = arr[x];
        }
    }

    int buckets = (max - min) / size;
    LinkedList bucketArr[buckets], *trav;

    for (x = 0; x < size; x++)
    {
        bucketArr[x] = NULL;
    }

    int bucket = 0;
    for (x = 0; x < size; x++)
    {
        bucket = (arr[x] - min) * (buckets) / (max - min + 1); // basically a hash function
        for (trav = &bucketArr[bucket]; (*trav) != NULL && (*trav)->data < arr[x]; trav = &(*trav)->link) {}
        LinkedList newNode = (LinkedList)malloc(sizeof(struct node));
        newNode->data = arr[x];
        newNode->link = (*trav);
        (*trav) = newNode;
    }

    int flag = 0;
    for (x = 0; x < size; x++)
    {
        for (trav = &bucketArr[x]; (*trav) != NULL; trav = &(*trav)->link)
        {
            arr[flag++] = (*trav)->data;
        }
    }
}

// look behind gnome sort
void gnomeSort(int arr[], int size)
{
    int x = 0;
    while (x < size)
    {
        if (x == 0 || arr[x] >= arr[x - 1])
        {
            x++;
        }
        else
        {
            int temp = arr[x];
            arr[x] = arr[x - 1];
            arr[x - 1] = temp;
            x--;
        }
    }
}

// Code generated by perplexity
void radixSort(int arr[], int size)
{
    int max = 0; // Initialize max to 0 instead of using arr[0]
    for (int x = 0; x < size; x++)
    {
        if (arr[x] > max)
        {
            max = arr[x];
        }
    }

    int num;
    for (num = 1; max / num > 0; num *= 10)
    {
        int freqArray[10] = {0};
        int outputArr[size];

        // Populate frequency array
        for (int x = 0; x < size; x++)
        {
            freqArray[(arr[x] / num) % 10]++;
        }

        // Get the prefix sum
        for (int x = 1; x <= 9; x++)
        { // Loop from 1 to 9 to avoid out-of-bounds access
            freqArray[x] += freqArray[x - 1];
        }

        // Map elements into output array based on their frequency counts
        for (int x = size - 1; x >= 0; x--)
        {
            outputArr[--(freqArray[(arr[x] / num) % 10])] = arr[x];
        }

        // Update input array with sorted elements from output array
        for (int x = 0; x < size; x++)
        {
            arr[x] = outputArr[x];
        }
    }
}

// Code generated by perplexity
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        int n1 = mid - low + 1;
        int n2 = high - mid;

        int left[n1], right[n2];

        int x;
        for (x = 0; x < n1; x++)
        {
            left[n1] = arr[low + x];
        }

        int y;
        for (y = 0; y < n2; y++)
        {
            right[n2] = arr[mid + 1 + y];
        }

        int i = 0;   // Initial index of first subarray
        int j = 0;   // Initial index of second subarray
        int k = low; // Initial index of merged subarray

        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of left[], if any
        while (i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }

        // Copy remaining elements of right[], if any
        while (j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}


