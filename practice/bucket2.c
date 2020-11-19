#include <stdio.h>
#include <stdlib.h>

struct Bucket
{
    int cnt;
    int *valure;
};

int com(const void *first, const void *second)
{
    int l = *(const int*)first;
    int r = *(const int*)second;

    if (l < r) return -1;
    if (l > r) return 1;
    return 0;
}

int sort(int *arr, int len)
{
    struct Bucket buckets[3];

    for (int i = 0; i < 3; i++)
    {
        buckets[i].cnt = 0;
        buckets[i].valure = malloc(sizeof(int) * len);
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            buckets[0].valure[buckets[0].cnt] = arr[i];
            buckets[0].cnt++;
        }
        else if (arr[i] > 10)
        {
            buckets[2].valure[buckets[2].cnt] = arr[i];
            buckets[2].cnt++;
        }
        else
        {
            buckets[1].valure[buckets[1].cnt] = arr[i];
            buckets[1].cnt++;
        }
    }

    for (int k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].valure, buckets[i].cnt, sizeof(int), com);

        for (int j = 0; j < buckets[i].cnt; j++)
        {
            arr[k + j] = buckets[i].valure[j];
        }
        k += buckets[i].cnt;
        free(buckets[i].valure);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 20, 30, 40, -1, -3, -9};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
