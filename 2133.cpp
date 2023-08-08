#include <bits/stdc++.h>
using namespace std;
int dp[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	for (i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (j = 0; j <= i - 4; j += 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
}