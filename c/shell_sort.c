#include <stdio.h>


void shell_sort(int *arr, int len)
{
    int h = 1;
    int min = 0;
    while (h < len/3)
    {
        h = h*3 + 1;
        printf("h: %d\n", h);
    }

    while (h >= 1)
    {
        for (int i = h; i < len; i += h)
        {
            for (int j = i; j > 0; j -= h)
            {
                if (arr[j - h] > arr[j])
                {
                    min = arr[j - h];
                    arr[j - h] = arr[j];
                    arr[j] = min;
                }
            }
        }
        h /= 3;
    }
}



int main()
{
	int test[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int test2[] = { 5, 4, 3, 2, 1};
    int test3[] = { 3 };

    int len = 0;

	for (int i = 0; i < 10; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");


    len = sizeof(test) / sizeof(test[0]);
	shell_sort(test, len);

	for (int i = 0; i < len; i++) {
		printf("%-3d", test[i]);
	}
	printf("\n");

    len = sizeof(test2) / sizeof(test2[0]);
	shell_sort(test2, len);
	for (int i = 0; i < len; i++) {
		printf("%-3d", test2[i]);
	}
	printf("\n");

    len = sizeof(test3) / sizeof(test3[0]);
	shell_sort(test3, len);
	for (int i = 0; i < len; i++) {
		printf("%-3d", test3[i]);
	}
	printf("\n");

	return 0;
}
