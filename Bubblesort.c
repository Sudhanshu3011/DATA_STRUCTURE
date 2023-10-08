#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *arr, int n)
{
    int temp, flag = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Working on the pass no:%d\n", i+1);
        flag = 1;
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
            if (flag)
            {
                return;
            }
        }
    }
}
void print(int *arr, int n)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[10], n = 10;
    for (int i = 0; i < 10; i++)
    {
        printf("The element[%d]:", i);
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    print(arr, n);

    return 0;
}