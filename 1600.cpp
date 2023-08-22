#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
int hdy[8] = { 1,2,2,1,-1,-2,-2,-1 }, hdx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int K, H, W;
bool board[200][200];
int visited[200][200][31];
queue<pair<pair<int, int>, int>> q;	// ÁÂÇ¥, ¸»Ã³·³ ÀÌµ¿ÇÑ È½¼ö

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K >> W >> H;
	int ny, nx, i, j, k;
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++)
			cin >> board[i][j];

	for (k = 0; k <= K; k++)
		for (i = 0; i < H; i++)
			for (j = 0; j < W; j++)
				visited[i][j][k] = INF;
	
	q.push({ {0,0},0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int horse = q.front().second;
		q.pop();
		if (y == H - 1 && x == W - 1) {
			cout << visited[y][x][horse] - 1;
			return 0;
		}
		if (horse < K) {
			for (i = 0; i < 8; i++) {
				ny = y + hdy[i];
				nx = x + hdx[i];
				if (ny < 0 || ny >= H || nx < 0 || nx >= W)
					continue;
				if (visited[ny][nx][horse + 1] <= visited[y][x][horse] + 1 || board[ny][nx])
					continue;
				visited[ny][nx][horse + 1] = visited[y][x][horse] + 1;
				q.push({ {ny,nx},horse + 1 });
			}
		}
		for (i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if (visited[ny][nx][horse] <= visited[y][x][horse] + 1 || board[ny][nx])
				continue;
			visited[ny][nx][horse] = visited[y][x][horse] + 1;
			q.push({ {ny,nx},horse});			
		}
	}
	cout << -1;
	return 0;
}