#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int sum[1025][1025];

// �˰��� å�� �ִ� Ǯ��
// ����: �� ������ ���� �� ���� (���� ���� ���� �� O(1))
// ����: �޸� ��뷮�� ����
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