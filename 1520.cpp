#include <bits/stdc++.h>
using namespace std;
int M, N;
int arr[500][500];
int dp[500][500];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int DFS(int y, int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	DFS(0, 0);
	cout << dp[0][0];
}

int DFS(int y, int x) {
	if (y == M - 1 && x == N - 1)
		return 1;
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (arr[ny][nx] < arr[y][x])
					dp[y][x] += DFS(ny, nx);				
			}
		}
	}
	return dp[y][x];
}