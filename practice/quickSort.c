#include <stdio.h>
#include <stdbool.h>

int partition(int *arr, int lo, int hi)
{
    int val = arr[lo];
    int i = lo, j = hi + 1;
    int tmp = 0;

    while (true)
    {
        while (arr[++i] < val)
        {
            if (i >= hi)
                break;
        }
        while (arr[--j] > val)
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
    arr[j] = val;
    return j;
}

void sort(int *arr, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }

    int index = partition(arr, lo, hi);
    sort(arr, lo, index - 1);
    sort(arr, index + 1, hi);
}


int main()
{
    int arr[] = { 10, 9, 8, 7, 6};
    int len = sizeof(arr)/sizeof(arr[0]);

    sort(arr, 0, len-1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
