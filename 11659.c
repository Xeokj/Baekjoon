#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, M, i, j, temp;
	scanf("%d %d", &N, &M);
	int* sum = (int*)calloc(N + 1, sizeof(int));
	for (i = 1; i <= N; i++) {
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;
	}
	while (M) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
		M--;
	}
	return 0;
}