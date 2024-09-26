#include <stdio.h>
#include "header.h"

int main() 
{
    int arr[12] = {10,4,12,9,3,1,7,8,6,11,5,2};

    printf("\n\nTournament Sort");

    printf("\n\nUnsorted: ");
    displayArr(arr, 12);    

    tournamentSort(arr, 12);

    printf("Sorted: ");
    displayArr(arr,12);

    return 0;
}