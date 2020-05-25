#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    int k = 0;

    int *tmp = malloc(sizeof(int) * (hi-lo+1));

    while (i <= mid && j <= hi)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= hi)
    {
        tmp[k++] = arr[j++];
    }

    for (i = lo, k = 0; i <= hi; i++, k++)
    {
        arr[i] = tmp[k];
    }

    free(tmp);
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
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, len-1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
