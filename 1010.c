#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dp[31][31];

int main() {
	int N, M, i, j;
	for (i = 1; i <= 30; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		dp[i][1] = i;
	}
	for (i = 3; i <= 30; i++)
		for (j = 2; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

	int test_case, T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &M);
		printf("%d\n", dp[M][N]);
	}
	return 0;
}