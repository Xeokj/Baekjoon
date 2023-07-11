#include<iostream>
#include <algorithm>
#define MAX 0x3f3f3f3f
using namespace std;

int dp[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, a, b, c;
	int i, j, k;
	cin >> n >> m;

	for (i = 1; i <= n; i++)
		fill(dp[i], dp[i] + n + 1, MAX);
	for (i = 1; i <= n; i++)
		dp[i][i] = 0;

	while (m--) {
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dp[i][j] == MAX) {
				cout << "0 ";
			}
			else
				cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}