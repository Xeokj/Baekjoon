#include <bits/stdc++.h>
using namespace std;

int board[600][600];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M, cnt;
void DFS(int y, int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int Ii, Ij, i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			char a;
			cin >> a;
			if (a == 'O')
				board[i][j] = 0;
			else if (a == 'X')
				board[i][j] = -1;
			else if (a == 'P')
				board[i][j] = 1;
			else if (a == 'I') {
				Ii = i;
				Ij = j;
			}
		}
	}
	DFS(Ii, Ij);
	if (cnt)
		cout << cnt;
	else
		cout << "TT";
}

void DFS(int y, int x) {
	board[y][x] = -1;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			if (board[ny][nx] == 1) {
				cnt++;
				DFS(ny, nx);
			}
			else if (board[ny][nx] == 0)
				DFS(ny, nx);
		}
	}
}