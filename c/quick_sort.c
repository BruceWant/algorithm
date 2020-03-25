#include <stdio.h>
#include <stdbool.h>


void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}


int partition(int *arr, int lo, int hi)
{
    int i = lo, j = hi+1;
    int val = arr[lo];

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
            break;
        swap(&(arr[i]), &(arr[j]));
    }
    swap(&(arr[j]), &(arr[lo]));

    return j;
}


void sort(int *arr, int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = partition(arr, lo, hi);
    sort(arr, lo, j-1);
    sort(arr, j+1, hi);
}


int main()
{
    int arr[] = {7, 1, 10, 6, 20, 1, 3, 5, 7, 9};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));

    sort(arr, 0, len - 1);

    // printf("len: %d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%-4d", arr[i]);
    }
    printf("\n");

    return 0;
}
