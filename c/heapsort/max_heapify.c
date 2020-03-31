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

int heap_max(int *arr)
{
    return arr[1];
}

int extract_max(int *arr, int *len)
{
    int max = 0, size = *len - 1;
    if (*len < 1)
    {
        return -1;
    }
    max = arr[1];
    arr[1] = arr[size--];
    max_heapify(arr, size, 1);
    *len = size + 1;

    return max;
}

int increase_key(int *arr, int k, int key)
{
    int i = k - 1;
    if (key < arr[i])
        return -1;
    arr[i] = key;
    while ((i > 1) && (arr[i/2] < arr[i]))
    {
        swap(&(arr[i]), &(arr[i/2]));
        i /= 2;
    }
    return i;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int len = (int) (sizeof(arr) / sizeof(arr[0]));
    int max = 0;

    for (int i = 1; i < len; i++)
        printf("%-4d", arr[i]);
    printf("\n");

    // heap_sort(arr, len);
    build_heap(arr, len - 1);

    max = extract_max(arr, &len);

    increase_key(arr, 5, 18);

    for (int i = 1; i < len; i++)
        printf("%-4d", arr[i]);
    printf("\n");
    printf("max: %d\n", max);
    return 0;
}
