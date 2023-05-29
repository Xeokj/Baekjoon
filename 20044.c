#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(int* a, int* b) {
	return *a - *b;
}

int main() {
	int n, i, j;
	scanf("%d", &n);
	int size = 2 * n, sum;
	int* arr = (int*)calloc(size, sizeof(int));
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	qsort(arr, size, sizeof(int), compare);
	int min = arr[0] + arr[size - 1];
	for (i = 0; i < n; i++) {
		sum = arr[i] + arr[size - i - 1];
		if (sum < min)
			min = sum;
	}
	printf("%d", min);
	free(arr);
	return 0;
}