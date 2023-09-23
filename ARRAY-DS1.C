#include <stdio.h>
int deletion(int arr[], int n, int a)
{
    int i;
    for (i =n; i <=a-1; i++)
    {
        arr[i - 1] = arr[i];
    }
    return 0;
}
int display(int arr[], int k)
{
    int i;
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[20] = {34, 45, 67, 7,56,67}, size, index, element;
    size = sizeof(arr) / sizeof(int);
    printf("Array before insertion.");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("insertion indexno:");
    scanf("%d", &index);
    deletion(arr, index, size);
    display(arr, 5);
}
