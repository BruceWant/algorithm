#include <stdio.h>


void merge(int *arr, int lo, int mid, int hi)
{
    int aux[hi-lo+1];
    int i = lo, j = mid + 1;

    for (int i = 0; i <= hi; i++)
    {
        aux[i] = arr[i];
        // printf("%-2d\n", aux[i]);
    }

    for(int k = lo; k <= hi; k++)
    {
        if (i > mid)
            arr[k] = aux[j++];
        else if (j > hi)
            arr[k] = aux[i++];
        else if (aux[i] < aux[j])
            arr[k] = aux[i++];
        else
            arr[k] = aux[j++];
    }
}


void sort(int *arr, int left, int right)
{
    if (left == right)
        return;

    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main()
{
    int arr[] = {0, 1, 10, 6, 20, 1, 3, 5, 7, 9};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));

    // merge(arr, 0, (len-1) / 2, len - 1);
    sort(arr, 0, len - 1);

    // printf("len: %d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%-4d", arr[i]);
    }
    printf("\n");

    return 0;
}
