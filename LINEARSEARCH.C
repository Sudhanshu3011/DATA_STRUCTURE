#include <stdio.h>
void search(int arr[], int num)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (arr[i] == num)
        {
            printf("The no is at given index%d.", i + 1);
        }
    }
    
    
}
int main()
{
    int arr[20] = {34, 45, 67, 7}, size, a, num;
    size = sizeof(arr) / sizeof(int);
    printf("Array .");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Enter the no for searching:");
    scanf("%d", &num);
    search(arr, num);

    if (a == 1)
    {
        printf("The no is not in the array.");
    }

    return 0;
}