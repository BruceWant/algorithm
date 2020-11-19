#include <stdio.h>
#include <stdlib.h>

struct Bucket
{
    int cnt;
    int *val;
};

int com(const void *first, const void *second)
{
    int l = *(const int*)first;
    int r = *(const int*)second;

    if (l < r) return -1;
    if (l > r) return 1;
    return 0;
}

void sort(int *arr, int len)
{
    struct Bucket tmparr[3];
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        tmparr[i].cnt = 0;
        tmparr[i].val = malloc(sizeof(int) * len);
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            tmparr[0].val[tmparr[0].cnt] = arr[i];
            tmparr[0].cnt++;
        }
        else if (arr[i] > 10)
        {
            tmparr[2].val[tmparr[2].cnt] = arr[i];
            tmparr[2].cnt++;
        }
        else
        {
            tmparr[1].val[tmparr[1].cnt] = arr[i];
            tmparr[1].cnt++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        qsort(tmparr[i].val, tmparr[i].cnt, sizeof(int), com);
        
        for (int j = 0; j < tmparr[i].cnt; j++)
        {
            arr[k+j] = tmparr[i].val[j];
        }
        k += tmparr[i].cnt;
        free(tmparr[i].val);
    }
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6, -1, -2, 30, 40};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
