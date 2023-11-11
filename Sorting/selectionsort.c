#include <stdio.h>
#include <stdlib.h>
//print the array
void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//selection sort code
int selectionsort(int A[], int n)
{
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
            {
                temp = A[j];
                A[j] = A[min];
                A[min] = temp;
            }
        }
    }
}
int main()
{
    int A[] = {12, 45, 18, 75, 45, 33};
    int n = 6;

    print(A, n);
    selectionsort(A, n);
    print(A, n);

    return 0;
}