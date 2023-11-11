#include <stdio.h>
#include <stdlib.h>

// print the array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// If a cretain array have the sorted data from a partion inside the array then the
// proper merge sort for that
void merge(int A[], int mid, int low, int high)
{
    int B[high];
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;

        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
        
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i < high; i++)
    {
        A[i] = B[i];
    }
    // print(A, high);
}

//recursive way 
void mergesort(int A[],int low, int high, int mid)
{


}

// partion point in the array
int partition(int A[], int n)
{
    int mid = 0, i = 0;
    while (i < n - 1 && A[i] < A[i + 1])
    {

        mid++;
        i++;
    }
    return mid;
}

int main()
{
    int A[] = {1, 4, 6, 8, 9, 5, 7, 13, 24, 56};
    int m = 10;
    print(A, m);
    int mid = partition(A, m);

    printf("Merge and the sorted array:");
    printf("\n");
    merge(A, mid, 0, m);
    print(A,m);

    return 0;
}