#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = 0;
    int len = hi - lo + 1;
    int tmp = arr[lo];

    int *tmpa = malloc(sizeof(len));

    while (i <= mid && j <= hi)
    {
        if (arr[i] > arr[j])
        {
            tmpa[k++] = arr[j++];
        }
        else
        {
            tmpa[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        tmpa[k++] = arr[i++];
    }
    while (j <= hi)
    {
        tmpa[k++] = arr[j++];
    }

    for (k = 0; k < len; k++)
    {
        arr[lo++] = tmpa[k];
    }
}

void sort(int *arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int mid = lo + (hi - lo) / 2;
    sort(arr, lo, mid);
    sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
