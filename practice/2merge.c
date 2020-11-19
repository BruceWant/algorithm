#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int lo, int mid, int hi)
{
    int *atmp = malloc(sizeof(int) * (hi - lo + 1));
    int i = lo;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= hi)
    {
        if (arr[i] > arr[j])
        {
            atmp[k++] = arr[j++];
        }
        else
        {
            atmp[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        atmp[k++] = arr[i++];
    }
    while (j <= hi)
    {
        atmp[k++] = arr[j++];
    }

    for (i = lo, k = 0; i <= hi;i++, k++)
    {
        arr[i]= atmp[k];
    }

    free(atmp);
}

void merge_sort(int *arr, int lo, int hi)
{
    if (hi <= lo)
    {
        return;
    }

    int mid = lo + (hi - lo) / 2;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1, 0};
    int len = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, len-1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
