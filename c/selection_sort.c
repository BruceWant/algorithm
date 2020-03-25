#include <stdio.h>

void selection_sort(int *arr, int len)
{
	int i, j, min, tmp;

	for (i = 0; i < len; i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if (arr[min] > arr[j]) {
				min = j;	
			}
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;	
	}
}



int main()
{
	int test[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	int i;
	for (i = 0; i < 10; i++) {
		printf("%-3d", test[i]);	/* %-3d minus means align */
	}					/* to left, 3 means a */
						/* number occupy thress */
						/* space. */
	printf("\n");


	selection_sort(test, 10);
	for (i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");


	return 0;
}
