#include <stdio.h>
#include <stdlib.h>


typedef struct Bucket
{
    int cnt;
    int *value;
} Bucket;


int com (const void *first, const void *second)
{
    int l = *(const int*)first, r = *(const int*)second;

    if (l < r) return -1;
    else if (l > r) return 1;
    return 0;
}

void bucket(int *arr, int len)
{
    Bucket buckets[3];

    for (int i = 0; i < 3; i++)
    {
        buckets[i].cnt = 0;
        buckets[i].value = malloc(sizeof(Bucket) * len);
        if (buckets[i].value == NULL)
        {
            printf("malloc failed\n");
            return;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            buckets[0].value[buckets[0].cnt++] = arr[i];
        }
        else if (arr[i] > 10)
        {
            buckets[2].value[buckets[2].cnt++] = arr[i];
        }
        else
        {
            buckets[1].value[buckets[1].cnt++] = arr[i];
        }
    }

    for (int i = 0, k = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].cnt, sizeof(int), com);

        for (int j = 0; j < buckets[i].cnt; j++)
        {
            arr[k+j] = buckets[i].value[j];
        }
        k += buckets[i].cnt;
        free(buckets[i].value);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    bucket(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
