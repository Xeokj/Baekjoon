#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(int* a, int* b) {
	return *a - *b;
}
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	int* arr = (int*)calloc(N, sizeof(int));
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	
	printf("%d", arr[K - 1]);
	free(arr);
	return 0;
}