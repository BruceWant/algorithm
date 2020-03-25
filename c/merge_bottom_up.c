#include <stdio.h>



void merge(int *arr, int lo, int mid, int hi)
{
    int aux[hi+1];
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = arr[k];
    }

    for (int k = lo; k <= hi; k++)
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


void sort(int *arr, int len)
{
    int min = 0;
    for (int sz = 1; sz < len; sz = sz+sz)
    {
        for (int lo = 0; lo < len-sz; lo += sz+sz)
        {
            if (lo+sz+sz-1 < len-1)
                min = lo+sz+sz-1;
            else
                min = len-1;
            merge(arr, lo, lo+sz-1, min);
        }
    }
}



int main()
{
    int arr[] = {0, 1, 10, 6, 20, 1, 3, 5, 7, 9};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));

    // merge(arr, 0, (len-1) / 2, len - 1);
    sort(arr, len);

    // printf("len: %d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%-4d", arr[i]);
    }
    printf("\n");

    return 0;
}
