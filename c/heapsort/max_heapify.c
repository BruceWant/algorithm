#include <stdio.h>


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void max_heapify(int *arr, int size, int i)
{
    // printf("%-2d", i);
    int index = i;
    int l = 2 * index, r = l + 1;
    int max = 0;

    
    if (l <= size && arr[l] > arr[index])
        max = l;
    else
        max = index;

    if (r <= size && arr[r] > arr[max])
        max = r;

    if (max != index)
    {
        swap(&(arr[index]), &(arr[max]));
        max_heapify(arr, size, max);
    }
}

void build_heap(int *arr, int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        max_heapify(arr, size, i);
    }
}


void heap_sort(int *arr, int len)
{
    int size = len - 1;
    build_heap(arr, size);
    for (int i = size; i >= 2; i--)
    {
        swap(&(arr[1]), &(arr[i]));
        size--;
        max_heapify(arr, size, 1);
    }
}


int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int len = (int) (sizeof(arr) / sizeof(arr[0]));

    for (int i = 1; i < len; i++)
        printf("%-4d", arr[i]);
    printf("\n");

    heap_sort(arr, len);

    for (int i = 1; i < len; i++)
        printf("%-4d", arr[i]);
    printf("\n");
    return 0;
}
