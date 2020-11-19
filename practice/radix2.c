#include <stdio.h>

int getMax(int *arr, int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    return arr[max];
}

void countSort(int *arr, int len, int exp)
{
    int tmpa[len];
    int cnt[10] = { 0 };

    for (int i = 0; i < len; i++)
    {
        cnt[(arr[i] / exp) % 10] += 1;
        tmpa[i] = arr[i];
    }

    for (int i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i-1];
    }

    for (int i = len - 1; i >= 0; i--)
    {
        cnt[tmpa[i] / exp % 10] -= 1;
        arr[cnt[tmpa[i] / exp % 10]] = tmpa[i];
    }
}

void sort(int *arr, int len)
{
    int max = getMax(arr, len);

    for (int i = 1; i < max; i *= 10)
    {
        countSort(arr, len, i);
    }
}


int main()
{
    int arr[] = {20, 40, 10, 9, 8, 7, 6, 789, 654, 298};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    // countSort(arr, len, 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
