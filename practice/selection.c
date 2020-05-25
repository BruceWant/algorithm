#include <stdio.h>


void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int idx = i;
        int tmp = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[idx] > arr[j])
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) /sizeof(arr[0]);

    selection_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
