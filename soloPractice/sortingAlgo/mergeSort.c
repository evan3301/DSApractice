#include <stdio.h>
#include <stdlib.h>

void merge(int *array , int left , int mid , int right)
{
    int i , j , k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    /// temp array
    int L[n1] , R[n2];

    /// copy data
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    /// index var & merge back arrays

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /// copy remnants of L[] and R[] arrays

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/// implement mergeSort

void mergeSort(int array[] , int left , int right) {
    if (left < right) {
        int mid = left + (right - 1) / 2;

        // sort first and second halves
        mergeSort (array , left , mid);
        mergeSort (array , mid + 1 , right);

        merge (array , left , mid , right);
    }
}

void printArray(int A[] , int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n" , A[i]);
    }
}

int main(void)
{
    int array[] = {14 , 24 , 8 , 9 , 5 , 3 , 17};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Given array is \n");
    printArray(array, arraySize);

    mergeSort(array, 0, arraySize - 1);

    printf("Sorted array is \n");
    printArray(array, arraySize);
    return 0;
}