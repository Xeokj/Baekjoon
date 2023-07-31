#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char arr[20][20];
int visited[26];	// 알파벳(A to Z)의 방문 체크
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
void DFS(int y, int x, int num);	// x,y: 좌표, num: 이동한 칸의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			cin >> arr[i][j];
	DFS(0, 0, 1);	// 시작점 포함이므로 1로 시작
	cout << ans;
}

void DFS(int y, int x, int num) {
	visited[arr[y][x] - 'A'] = 1;	// 알파벳 방문 체크
	if (num > ans)
		ans = num;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			// 인접한 곳에 방문하지 않은 알파벳이 있다면 이동
			if (!visited[arr[ny][nx] - 'A'])
				DFS(ny, nx, num + 1);
		}
	}
	visited[arr[y][x] - 'A'] = 0;	// 방문 안 한 것으로 초기화
}