#include <bits/stdc++.h>
using namespace std;
// 2206번: 벽 부수고 이동하기
// 상태를 차원으로 다루는 아이디어가 필요
bool board[1000][1000];
int visited[1000][1000][2];
// visited[][][0]: 벽을 부순 적 없는 상태에서의 이동 횟수 저장
// visited[][][1]: 벽을 한 번 부순 상태에서의 이동 횟수 저장
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '1')
				board[i][j] = 1;
		}
	}
	BFS();
	if (!visited[N - 1][M - 1][0] && !visited[N - 1][M - 1][1])
		cout << -1;
}

void BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int broke = q.front().second;
		// broke: 벽을 부순 적이 없으면 0, 있으면 1
		q.pop();
		if (y == N - 1 && x == M - 1) {
			cout << visited[y][x][broke];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];
			if (dy < 0 || dy >= N || dx < 0 || dx >= M)
				continue;
			if (visited[dy][dx][broke])
				continue;
			if (!board[dy][dx]) {
				// 0인 경우
				visited[dy][dx][broke] = visited[y][x][broke] + 1;
				q.push({ {dy,dx},broke });
			}
			else if (board[dy][dx] && !broke) {
				// 벽을 처음 부수는 경우
				visited[y][x][1] = visited[y][x][0];
				// 원래의 위치로 못 돌아가도록
				visited[dy][dx][1] = visited[y][x][0] + 1;
				q.push({ { dy,dx }, 1 });
			}
		}
	}
}