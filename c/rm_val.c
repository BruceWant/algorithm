#include <stdio.h>



void remove_val(int *arr, int len, int val)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[len - 1];
            --len;
        }
    }
}


int main()
{
    int arr[] = { 0 };
    int len = (int) (sizeof(arr) / sizeof(arr[0]));


    for (int i = 0; i < len; i++)
        printf("%-2d", arr[i]);
    printf("\n");

    remove_val(arr, len, 2);

    for (int i = 0; i < len; i++)
        printf("%-2d", arr[i]);
    printf("\n");

    return 0;
}
