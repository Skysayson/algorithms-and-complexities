#include <stdio.h>
#include "header.h"

void displayArr(int arr[], int size) 
{
    int x;
    for(x = 0; x < size; x++) {
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

void bubbleSort(int arr[], int size) 
{
    int x,y;
    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            if(arr[x] < arr[y]) {
                swap(&arr[x], &arr[y]);
            }
        }
    }
}

void combSort(int arr[], int size) 
{
    int x, gap = size, swapped = 1;

    while(gap > 1 || swapped) {
        gap /= 1.3;
        swapped = 0;

        for(x = 0; x + gap < size; x++) {
            if(arr[x] > arr[x + gap]) {
                swap(&arr[x], &arr[x + gap]);
                swapped = 1;
            }
        }
    }
}

void insertionSort(int arr[], int size) 
{
    int x,y,temp;
    for(x = 0; x < size; x++) {
        for(y = x-1; y >= 0; y--) {
            if(arr[y] > arr[y+1]) {
                swap(&arr[y], &arr[y+1]);
            }
        }
    }   
}