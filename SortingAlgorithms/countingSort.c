#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[7] = {4,2,2,8,3,3,1};

    printf("\n\nCounting Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 7);    

    countingSort(arr, 7);

    printf("Sorted: ");
    displayArr(arr,7);

    return 0;
}