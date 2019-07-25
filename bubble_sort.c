#include <stdio.h>


void bubble_sort(int *arr, int len)
{
	int i, j, tmp;

	for (i = len -1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}


int main()
{
	int test[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	for (int i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");

	bubble_sort(test, 10);

	for (int i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");

	return 0;
}
