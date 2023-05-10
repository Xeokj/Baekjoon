#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dp[10][2];
// dp[n][1]: n으로 끝나는 수의 경우의 수
// dp[n][0]: 이전 자릿수가 n으로 끝나는 경우의 수

int main() {
	int N, i, ans = 0;
	scanf("%d", &N);

	for (i = 1; i < 10; i++)
		dp[i][0] = 1;

	while (N > 1) {
		dp[0][1] = dp[1][0];
		for (i = 1; i < 9; i++) {
			dp[i][1] = (dp[i - 1][0] + dp[i + 1][0]) % 1000000000;
		}
		dp[9][1] = dp[8][0];

		for (i = 0; i < 10; i++)
			dp[i][0] = dp[i][1];
		N--;
	}

	for (i = 0; i < 10; i++)
		ans = (ans + dp[i][0]) % 1000000000;
	
	printf("%d", ans);
	return 0;
}