#include <bits/stdc++.h>
using namespace std;
int sum[1025][1025];

// 내 풀이
// 장점: 메모리가 더 적게 듦
// 단점: 시간이 더 오래 걸림 (구간 합을 구할 때 O(N))
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, num, i, j;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> num;
			sum[i][j] += (sum[i][j - 1] + num);
		}
	}
	int x1, y1, x2, y2;
	while (M--) {
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = x1; i <= x2; i++)
			ans += (sum[i][y2] - sum[i][y1 - 1]);
		cout << ans << "\n";
	}
}