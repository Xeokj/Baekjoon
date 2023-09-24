#include <bits/stdc++.h>
using namespace std;
// 백준 18290번: NM과 K (1) (실버 1)
int N, M, K, ans = -40000;
int arr[11][11], visited[11][11];
void backtr(int r, int c, int num, int sum);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M >> K;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cin >> arr[i][j];
	backtr(1, 1, 0, 0);
	cout << ans;
}

void backtr(int r, int c, int num, int sum) {
	if (num == K) {
		if (sum > ans)
			ans = sum;
		return;
	}
	if (c > M) {
		r++;
		c = 1;
	}
	if (r > N)
		return;
	int i = r, j = c;
	while (i <= N) {
		if (!visited[i - 1][j]) {
			visited[i][j] = 1;
			backtr(i, j + 2, num + 1, sum + arr[i][j]);
			visited[i][j] = 0;
		}
		j++;
		if (j > M) {
			i++;
			j = 1;
		}
	}
}