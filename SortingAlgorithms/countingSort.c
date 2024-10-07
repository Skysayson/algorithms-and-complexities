#include <stdio.h>
#include "header.h"

int main()
{
    int arr[7] = {4, 2, 2, 8, 3, 3, 1};

    printf("\n\nCounting Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 7);

    int *catchArr = countingSort(arr, 7);

    if (catchArr == NULL)
    {
        printf("Sorting failed due to memory allocation error.\n");
        return 1;
    }

    printf("Sorted: ");
    displayArr(catchArr, 7);

    return 0;
}