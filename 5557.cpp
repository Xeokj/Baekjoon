#include <bits/stdc++.h>
using namespace std;
// 백준 5557번: 1학년 (골드 5)
long long dp[99][21];
int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	dp[0][arr[0]] = 1;
	for (i = 1; i < N - 1; i++) {
		for (j = 0; j <= 20; j++) {
			// arr[i - 1] 숫자까지 계산한 결과가 j인 경우가 있을 때
			if (dp[i - 1][j]) {
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 2][arr[N - 1]];
}