#include <bits/stdc++.h>
using namespace std;
// 백준 2583번: 영역 구하기 (실버 1)
bool board[101][101], visited[101][101];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, i, j, ans = 0;
	cin >> M >> N >> K;
	int y1, x1, y2, x2;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = y1; i < y2; i++)
			for (j = x1; j < x2; j++)
				board[i][j] = 1;
	}
	vector<int> arr;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (!board[i][j] && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				int area = 1;
				while (!q.empty()) {
					int cury = q.front().first;
					int curx = q.front().second;
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int ny = cury + dy[dir];
						int nx = curx + dx[dir];
						if (ny < 0 || ny >= M || nx < 0 || nx >= N)
							continue;
						if (!board[ny][nx] && !visited[ny][nx]) {
							q.push({ ny,nx });
							area++;
							visited[ny][nx] = 1;
						}
					}
				}
				ans++;
				arr.push_back(area);
			}
		}
	}
	cout << ans << "\n";
	sort(arr.begin(), arr.end());
	for (i = 0; i < ans; i++)
		cout << arr[i] << ' ';
}