#include <stdio.h>


void sort(int *arr, int len)
{
    int h = 1;
    int tmp = 0;

    while (h < len / 3)
    {
        h = h * 3 + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < len; i += h)
        {
            for (int j = i; j > 0; j -= h)
            {
                if (arr[j] < arr[j-h])
                {
                    tmp = arr[j];
                    arr[j] = arr[j-h];
                    arr[j-h] = tmp;
                }
            }
        }
        h /= 3;
    }
}


int main()
{
    int arr[] = { 10, 9, 8, 7, 6};
    int len = sizeof(arr) /sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
