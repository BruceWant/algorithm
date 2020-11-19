#include <stdio.h>
#include <stdlib.h>


void sort(int *arr, int len, int max)
{
    int *cnt = malloc(sizeof(int) * (max + 1));
    int tmpa[len];

    if (cnt == NULL)
    {
        printf("malloc failed\n");
    }

    for (int i = 0; i <= max; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        cnt[arr[i]] += 1;
        tmpa[i] = arr[i];
    }

    for (int i = 1; i <= max; i++)
    {
        cnt[i] += cnt[i-1];
    }

    for (int i = len - 1; i >= 0; i--)
    {
        cnt[tmpa[i]] -= 1;
        arr[cnt[tmpa[i]]] = tmpa[i];
    }
    
    free(cnt);
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
