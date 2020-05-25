#include <stdio.h>



void sort(int *arr, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


int main()
{
    int arr[] = { 10, 9, 8, 7, 6, 5, 4 };

    int len = sizeof(arr) / sizeof(arr[0]);
    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
