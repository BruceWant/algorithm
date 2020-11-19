#include <stdio.h>


void sort(int *arr, int len)
{
    int min;
    int tmp;

    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i ++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
