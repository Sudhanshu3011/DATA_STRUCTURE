#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// print the array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// function for the merge of different array
void merge(int A[], int B[], int C[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    // if the araay A[i] is left out with some variable then they allocated directly
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    // if the araay B[j] is left out with some variable then they allocated directly
    while (j < m)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}

int main()
{
    int A[] = {4, 7, 9, 10};

    int B[] = {5, 8, 12, 14};
    int m, n;
    m = 4;
    n = 4;
    int C[m + n ];
    merge(A, B, C, m, n);
    print(A, m);
    print(B, n);
    print(C, m + n );

    return 0;
}