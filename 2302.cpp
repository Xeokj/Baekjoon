#include <bits/stdc++.h>
using namespace std;

int dp[42][2] = { {0,1},{0,1} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i;
	cin >> N >> M;
	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}
	int ans = dp[N][0] + dp[N][1];
	if (M) {
		ans = 1;
		int temp = 0, num;
		for (i = 0; i < M; i++) {
			cin >> num;
			ans *= (dp[num - temp - 1][0] + dp[num - temp - 1][1]);
			temp = num;
		}
		ans *= (dp[N - temp][0] + dp[N - temp][1]);
	}
	cout << ans;
}