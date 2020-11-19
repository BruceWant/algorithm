#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int lo, int mid, int hi)
{
    int *tmparr = malloc(sizeof(int) * (hi - lo + 1));
    int i = lo, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= hi)
    {
        if (arr[i] <= arr[j])
        {
            tmparr[k++] = arr[i++];
        }
        else
        {
            tmparr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        tmparr[k++] = arr[i++];
    }
    while (j <= hi)
    {
        tmparr[k++] = arr[j++];
    }

    for (k = 0, i = lo; i <= hi; i++, k++)
    {
        arr[i] = tmparr[k];
    }

    free(tmparr);
}

void sort(int *arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int mid = lo + (hi - lo) / 2;
    sort(arr, lo, mid);
    sort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
