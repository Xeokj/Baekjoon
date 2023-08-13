#include <bits/stdc++.h>
using namespace std;
bool board[101][101];
int dist[101][101];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M;
queue<pair<int, int>> q;
void BFS();

int main() {
	cin >> M >> N;
	int i, j;
	for (i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (j = 1; j <= M; j++) {
			dist[i][j] = N * M;
			if (input[j - 1] == '1')
				board[i][j] = 1;			
			else
				board[i][j] = 0;
		}
	}
	dist[1][1] = 0;
	BFS();
	cout << dist[N][M];
}

void BFS() {
	q.push({ 1,1 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny > 0 && nx > 0 && ny <= N && nx <= M) {
				if (board[ny][nx]) {
					if (dist[ny][nx] > dist[y][x] + 1) {
						dist[ny][nx] = dist[y][x] + 1;
						q.push({ ny,nx });
					}
				}
				else {
					if (dist[ny][nx] > dist[y][x]) {
						dist[ny][nx] = dist[y][x];
						q.push({ ny,nx });
					}
				}				
			}
		}
	}
}