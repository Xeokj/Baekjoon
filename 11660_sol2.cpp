#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int sum[1025][1025];

// 알고리즘 책에 있는 풀이
// 장점: 더 빠르게 구할 수 있음 (구간 합을 구할 때 O(1))
// 단점: 메모리 사용량이 증가
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i, j;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}
	int x1, y1, x2, y2;
	while (M--) {
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
}