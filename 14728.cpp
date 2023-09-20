#include <bits/stdc++.h>
using namespace std;
// ¹éÁØ 14728¹ø: º­¶ôÄ¡±â (°ñµå 5)
int dp[101][10001];
int K[101], S[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, T, i, j;
	cin >> N >> T;
	for (i = 1; i <= N; i++)
		cin >> K[i] >> S[i];
	
	for (i = 1; i <= N; i++)
		for (j = 1; j <= T; j++)
			if (j - K[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
			else
				dp[i][j] = dp[i - 1][j];
	cout << dp[N][T];
}