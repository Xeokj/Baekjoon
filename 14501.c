#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct _Consult {
	int T;
	int P;
} Consult;

int main() {
	int N, i, j;
	scanf("%d", &N);
	Consult* consult = (Consult*)calloc(N, sizeof(Consult));
	int* dp = (int*)calloc(N + 1, sizeof(int));

	for (i = 0; i < N; i++)
		scanf("%d %d", &consult[i].T, &consult[i].P);

	int idx, date, max = 0;
	for (i = 1; i <= N; i++) {
		idx = i - 1;
		date = idx + consult[idx].T;
		if (date <= N) {
			dp[date] = max(dp[idx] + consult[idx].P, dp[date]);
			for (j = date + 1; j <= N && dp[date] > dp[j]; j++) {
				dp[j] = dp[date];
			}
			if (dp[date] > max)
				max = dp[date];
		}
	}
	printf("%d", max);
	free(consult);
	free(dp);
	return 0;
}