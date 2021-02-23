#include <stdio.h>


int bubble_sort(int *arr, int len)
{
    if (NULL == arr || len <= 0)
    {
        return -1;
    }

    int tmp = 0;
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return 0;
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
