#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 21921번: 블로그 (실버 3)

int N, X, num, ans, cnt;
vector<int> sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> X;
	sum.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> num;
		sum.push_back(sum[i - 1] + num);
	}
	for (int i = 0; i <= N - X; i++) {
		if (ans < sum[i + X] - sum[i]) {
			ans = sum[i + X] - sum[i];
			cnt = 1;
		}
		else if (ans == sum[i + X] - sum[i])
			cnt++;
	}
	if (ans == 0)
		cout << "SAD";
	else
		cout << ans << "\n" << cnt;
	return 0;
}