#include <stdio.h>
// insert sorting adaptive and stability as well
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int insertsort(int *arr, int n)
{
    int i, j, key;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        //swaping if the number is gretaer than the previous one
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {24, 57, 86, 2, 45, 21, 1, 0, 43};
    int n = 9;
    print(arr, n);
    insertsort(arr, n);
    printf("\n");
    print(arr, n);
    return 0;
}