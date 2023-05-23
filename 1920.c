#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int A[100000];
int B[100000];

int compare(const void* a, const void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int main() {
	int N, M, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	qsort(A, N, sizeof(int), compare);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
		scanf("%d", &B[i]);

	for (i = 0; i < M; i++)
		printf("%d\n", find(B[i], 0, N - 1));
	
	return 0;
}

int find(int num, int start, int end) {
	if (end < start) {
		return 0;
	}
	int middle = (start + end) / 2;
	if (num == A[middle])
		return 1;
	else if (num < A[middle])
		find(num, start, middle - 1);
	else
		find(num, middle + 1, end);
}