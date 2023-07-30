#include <bits/stdc++.h>
using namespace std;

int space[500][500];
int visited[500][500];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M, ans;
void DFS(int y, int x, int d, int sum);
void T(int y, int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> space[i][j];

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			DFS(i, j, 1, 0);
			T(i, j);
		}
	}
	cout << ans;
}

void DFS(int y, int x, int d, int sum) {
	sum += space[y][x];
	visited[y][x] = 1;
	if (d == 4) {
		if (sum > ans)
			ans = sum;
		visited[y][x] = 0;
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			if (!visited[ny][nx])
				DFS(ny, nx, d + 1, sum);
		}
	}
	visited[y][x] = 0;
}

void T(int y, int x) {
	int sum, dir, ny, nx;
	for (int i = 0; i < 4; i++) {
		sum = space[y][x];
		for (dir = 0; dir < 4; dir++) {
			if (dir == i)
				continue;
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				sum += space[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}