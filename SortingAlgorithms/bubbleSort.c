#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[5] = {23,1,10,5,2};

    printf("\n\nBubble Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 5);    

    bubbleSort(arr, 5);

    printf("Sorted: ");
    displayArr(arr,5);

    return 0;
}