#include <stdio.h>
#include <stdlib.h>

void* xmalloc(size_t size)
{
    void *tmp = malloc(size);
    if (!tmp && !size)
    {
        return NULL;
    }
    return tmp;
}

void sort(int *arr, int len, int max)
{
    int *tmparr = malloc(sizeof(int) * len);
    int *cnt = malloc(sizeof(int) * (max + 1));

    for (int i = 0; i <= max; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        cnt[arr[i]] += 1;
        tmparr[i] = arr[i];
    }

    for (int i = 1; i <= max; i++)
    {
        cnt[i] += cnt[i-1];
    }

    for (int i = 0; i < len; i++)
    {
        cnt[tmparr[i]] -= 1;    /* Become a index, meanwhile sum - 1; */
        arr[cnt[tmparr[i]]] = tmparr[i];
    }
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len, 10);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
