#include <stdio.h>
#include <stdbool.h>


int partition(int *arr, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int value = arr[lo];
    int tmp = 0;

    while (true)
    {
        while (arr[++i] < value)
        {
            if (i >= hi)
                break;
        }
        while (arr[--j] > value)
        {
            if (j <= lo)
                break;
        }
        if (i >= j)
        {
            break;
        }
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    arr[lo] = arr[j];
    arr[j] = value;

    return j;
}

void sort(int *arr, int lo, int hi)
{
    if (lo >= hi)
        return;
    
    int mid = partition(arr, lo, hi);
    sort(arr, lo, mid - 1);
    sort(arr, mid + 1, hi);
}


int main()
{
    int arr[] = {10, 8, 9, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
