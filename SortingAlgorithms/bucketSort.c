#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[10] = {11,9,21,8,17,19,13,1,24,12};

    printf("\n\nBucket Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 10);    

    bucketSort(arr, 10);

    printf("Sorted: ");
    displayArr(arr, 10);

    return 0;
}