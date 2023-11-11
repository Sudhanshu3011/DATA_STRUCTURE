#include <stdio.h>
#include <stdlib.h>
// Printing the array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Partion of the array algo code
int partion(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

// Quicksort algorithm
void quicksort(int arr[], int low, int high)
{
    int partionIndex;

    if (low < high)
    {
        partionIndex = partion(arr, low, high);
        // print(arr,10);
        quicksort(arr, low, partionIndex - 1);
        quicksort(arr, partionIndex + 1, high);
    }
}
int main()
{
    int A[] = {8, 5, 9, 7, 2, 4, 6, 7, 1, 3};
    int n = 10;
    print(A, n);
    quicksort(A, 0, n - 1);
    print(A, n);
    return 0;
}