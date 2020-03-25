#include <stdio.h>


int search(int *arr, int len, int var)
{
    int i = len / 2;
    int tmp = i;
    int lo = 0, hi = len;

    while (0 <= i && i < len)
    {
        if (var < arr[i])
        {
            if (i == (tmp + 1))
                return i;
            if (i == 0)
                return 0;
            tmp = i;
            hi = i;
            i = lo + (i - lo) / 2;
        }
        else if (arr[i] < var)
        {
            if (i == (tmp - 1))
                return i + 1;
            else if (i == tmp)
                return i + 1;
            tmp = i;
            lo = i;
            i = i + (hi - i) / 2;
        }
        else
        {
            return i;
        }
    }
    return len;
}


int main()
{
    int arr[] = {4, 8};
    int var = 8;
    int len = (int) (sizeof(arr) / sizeof(arr[0]));
    int insert = 0;

    insert = search(arr, len, var);
    printf("%d\n", insert);

    for (int i = 0; i < len; i++)
    {
        printf("%-2d", i);
    }
    printf("\n");

    for (int j = 0; j < len; j++)
    {
        printf("%-2d", arr[j]);
    }
    printf("\n");
}
