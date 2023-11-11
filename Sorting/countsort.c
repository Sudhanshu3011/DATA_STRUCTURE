#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n ");
}

// maximum
int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

// count sort
void countsort(int A[], int n)
{
    int i, j;

    int max = maximum(A, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    // set all the value of the Array count as zero
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    //
    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count);
}
int main()
{
    int A[] = {12, 3, 5, 7, 9, 7, 4, 5, 13};
    int n = 9;
    print(A, n);
    countsort(A, n);
    print(A, n);

    
    return 0;
}