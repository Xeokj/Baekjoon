#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i, j;
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	cout << dp[N];
}