#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, N, i;
	cin >> T;
	while (T--) {
		cin >> N;
		for (i = 1; i <= N; i++)
			cin >> dp[i][0];
		for (i = 1; i <= N; i++)
			cin >> dp[i][1];
		for (i = 2; i <= N; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + dp[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + dp[i][1];
		}
		int ans = max(dp[N][0], dp[N][1]);
		cout << ans << "\n";
	}
}