#include <stdlib.h>

void quickSort(int* array , int low , int high) {
    if (low < high) {
        int p = partition(array , low , high);
        quickSort(array , low , p - 1);
        quickSort(array , p + 1 , high);
    }
}

int partition(int* array , int low , int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i] , &array[j])
        }
    }
    swap(&array[i + 1] , &array[high]);
    return (i + 1);
}

void swap(int* a , int* b) {
    int t = *a
    a* = *b
    *b = t;
}

int main(void)
{
    int array[] = {2 , 8 , 9 , 14 , 19 , 7};
    int n = sizeof(array) / sizeof(array[0]);

    quickSort(array , 0 , n-1);
    printf("Sorted array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d" , array[i]);
    }
    return 0;
}