#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i;
	cin >> N;
	vector<int> T(N + 1), P(N + 1), dp(N + 1);
	for (i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	dp[N] = 0;
	int Max = 0;
	for (i = N - 1; i >= 0; i--) {
		int end = i + T[i];
		if (end <= N) {
			dp[i] = max(Max, dp[end] + P[i]);
			if (dp[i] > Max)
				Max = dp[i];
		}
		else
			dp[i] = Max;
	}
	cout << dp[0];
}