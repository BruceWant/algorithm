#include <stdio.h>

void print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%-2d", arr[i]);
    printf("\n");
}

void counting_sort(const int *src, int *dst, int len, int max)
{
    int cnt[max+1];

    for (int i = 0; i <= max; i++)
    {
        cnt[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        cnt[src[i]] = cnt[src[i]] + 1;
    }
    for (int i = 1; i <= max; i++)
    {
        cnt[i] = cnt[i] + cnt [i-1];
    }
    // print(cnt, max+1);
    for (int i = 0; i <= max; i++)
    {
        cnt[i] -= 1;
    }

    for (int i = len-1; i >= 0; i--)
    {
        dst[cnt[src[i]]] = src[i];
        cnt[src[i]] -= 1;
    }
}


int main()
{
    int src[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
    int len = (int)(sizeof(src) / sizeof(src[0]));
    int dst[len];

    for (int i = 0; i < len; i++)
        printf("%-2d", src[i]);
    printf("\n");

    // 5 is the largest number in src[]
    counting_sort(src, dst, len, 5);

    for (int i = 0; i < len; i++)
        printf("%-2d", dst[i]);
    printf("\n");

    return 0;
}
