#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);

	int** dp = (int**)calloc(N + 1, sizeof(int*));
	for (i = 0; i < N + 1; i++)
		dp[i] = (int*)calloc(N + 1, sizeof(int));

	for (i = 1; i <= N; i++) {
		dp[i][0] = 1;	// (n, 0) = 1
		dp[i][i] = 1;	// (n, n) = 1
		dp[i][1] = i;	// (n, 1) = 1
	}

	for (i = 3; i <= N; i++) {
		for (j = 2; j < i && j <= K; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
	}

	printf("%d", dp[N][K]);

	for (i = 0; i < N; i++)
		free(dp[i]);
	free(dp);
	return 0;
}