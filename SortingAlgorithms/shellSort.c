#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[5] = {1,2,3,4,5};

    printf("\n\nShell Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 5);    

    shellSort(arr, 5);

    printf("Sorted: ");
    displayArr(arr,5);

    return 0;
}