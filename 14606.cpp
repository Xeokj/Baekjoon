#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i;
	cin >> N;
	vector<int> dp(N + 1);
	for (i = 2; i <= N; i++) {
		int tmp1 = i / 2;
		int tmp2 = i - tmp1;
		dp[i] = tmp1 * tmp2 + dp[tmp1] + dp[tmp2];
	}
	cout << dp[N];
}