#include <bits/stdc++.h>
using namespace std;
int arr[2000], dp[2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j, ans = 0;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	for (i = 0; i < N; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << N - ans;
}