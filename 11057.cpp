#include <bits/stdc++.h>
using namespace std;

int dp[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j, ans = 0;
	cin >> N;
	fill(dp, dp + 10, 1);
	while (--N) {
		for (i = 9; i >= 0; i--) {
			for (j = 0; j < i; j++) {
				dp[i] += dp[j];
			}
			dp[i] %= 10007;
		}
	}
	for (i = 0; i < 10; i++)
		ans += dp[i];
	cout << ans % 10007;
}