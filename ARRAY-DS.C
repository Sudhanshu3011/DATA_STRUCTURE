#include <stdio.h>

int insertion(int arr[], int a, int b, int e)
{
    int i;
    for (i = a - 1; i >= b; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[b] = e;
    return 0;
}
void show(int arr[], int a)
{
    printf("Inserted array is.");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[20] = {34, 45, 67, 7}, size, index, element;
    size = sizeof(arr) / sizeof(int);
    printf("Array before insertion.");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("insertion indexno:");
    scanf("%d", &index);
    printf("Enter the element:");
    scanf("%d", &element);

    insertion(arr, size, index, element);

    show(arr, 5);

    return 0;
}