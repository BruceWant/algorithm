#include <stdio.h>

void sort(int *arr, int len)
{
    int tmp = 0;

    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}


int main()
{
    int arr[] = { 10, 9, 8, 7, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
