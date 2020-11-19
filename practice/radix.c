#include <stdio.h>


int getMax(int *arr, int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }

    return arr[max];
}

void countSort(int *arr, int len, int exp)
{
    int tmparr[len];
    int cnt[10] = { 0 };

    for (int i = 0; i < len; i++)
    {
        cnt[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i-1];
    }

    for (int i = len - 1; i >= 0; i--)
    {
        cnt[(arr[i] / exp) % 10]--;
        tmparr[cnt[(arr[i] / exp) % 10]] = arr[i];
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = tmparr[i];
    }
}


void radix(int *arr, int len)
{
    int max = getMax(arr, len);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, len, exp);
    }
}


int main()
{
    int arr[] = {20, 40, 10, 9, 8, 7, 6, 789, 654, 298};
    int len = sizeof(arr) / sizeof(arr[0]);

    radix(arr, len);

    // countSort(arr, len, 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
