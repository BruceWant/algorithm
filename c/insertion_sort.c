#include <stdio.h>


void insertion_sort(int *arr, int len)
{
    int i, j, min;

    for (i = 1; i < len; i++)
    {
        min = arr[i - 1];
        for (j = i; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                min = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = min;
            }
        }

    }
}




int main()
{
	int test[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int test2[2] = { 3, 2};
    int test3[1] = { 3 };

	for (int i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");


	insertion_sort(test, 10);

	for (int i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");

	insertion_sort(test2, 2);
	for (int i = 0; i < 2; i++) {
		printf("%-3d", test2[i]);
	}
	printf("\n");

	insertion_sort(test3, 1);
	for (int i = 0; i < 1; i++) {
		printf("%-3d", test3[i]);
	}
	printf("\n");

	return 0;
}
