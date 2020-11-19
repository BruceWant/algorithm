#include <stdio.h>
#include <stdlib.h>


void maxHeapify(int *arr, int len, int index)
{
    int l = 2 * index + 1, r = 2 * index + 2;
    int largest = index;

    if (l < len && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < len && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != index)
    {
        int tmp = 0;

        tmp = arr[largest];
        arr[largest] = arr[index];
        arr[index] =tmp;

        maxHeapify(arr, len, largest);
    }
}

void buildHeap(int *arr, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        maxHeapify(arr, len, i);
    }
}

void sort(int *arr, int len)
{
    int tmp = 0;

    buildHeap(arr, len);

    for (int i = len - 1; i >= 0; i--)
    {
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        
        len--;
        maxHeapify(arr, len, 0);
    }
}


int main()
{
    int arr[] = {10, 9, 8, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
