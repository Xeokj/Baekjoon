#include <bits/stdc++.h>
using namespace std;

long long dp[91][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i;
	cin >> N;
	dp[1][1] = 1;
	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[N][0] + dp[N][1];
}