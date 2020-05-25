#include <stdio.h>


void insert_sort(int *arr, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j-1] > arr[j])
            {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) /sizeof(arr[0]);

    insert_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
