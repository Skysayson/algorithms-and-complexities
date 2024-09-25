#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[5] = {23,1,10,5,2};

    printf("\n\nComb Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 5);    

    combSort(arr, 5);

    printf("Sorted: ");
    displayArr(arr,5);

    return 0;
}