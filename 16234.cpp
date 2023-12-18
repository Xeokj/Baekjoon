#include <bits/stdc++.h>
using namespace std;
// 백준 16234번: 인구 이동 (골드 4)
int board[50][50];
bool visited[50][50];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, L, R, i, j, ans = 0;
	cin >> N >> L >> R;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> board[i][j];
	bool flg = 1;	// 인구 이동이 일어나는지 표시
	while (flg) {
		flg = 0;	// 인구 이동이 일어나지 않는다고 가정
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				// 아직 방문하지 않은 곳을 기준으로 BFS 탐색
				if (!visited[i][j]) {
					queue<pair<int, int>> q;	// BFS에 사용할 큐
					queue<pair<int, int>> coord;	// 인구 이동이 일어나는 좌표를 저장
					q.push({ i,j });
					coord.push({ i,j });
					visited[i][j] = 1;
					int area = 1;	// 방문한 나라(좌표)의 개수 (연합을 이루고 있는 칸의 개수)
					int sum = board[i][j];	// 연합의 인구수
					while (!q.empty()) {
						int cury = q.front().first;
						int curx = q.front().second;
						q.pop();
						int curp = board[cury][curx];
						for (int dir = 0; dir < 4; dir++) {
							int ny = cury + dy[dir];
							int nx = curx + dx[dir];
							if (ny < 0 || ny >= N || nx < 0 || nx >= N)
								continue;
							// 국경선을 열 수 있을 때
							if (abs(board[ny][nx] - curp) >= L && abs(board[ny][nx] - curp) <= R && !visited[ny][nx]) {
								q.push({ ny,nx });
								coord.push({ ny,nx });
								area++;
								sum += board[ny][nx];
								visited[ny][nx] = 1;
							}
						}
					}
					// area가 2 이상이면 인구 이동이 일어났으므로 flg를 1로 바꿔줌
					if (area > 1)
						flg = 1;
					int np = sum / area;	// 인구 이동이 일어난 후의 각 나라별 인구수
					while (!coord.empty()) {
						int y = coord.front().first;
						int x = coord.front().second;
						coord.pop();
						board[y][x] = np;	// 인구수 업데이트
					}
				}
			}
		}
		if (flg)
			ans++;	// 인구 이동이 일어났을 경우
		// visited를 모두 0으로 초기화
		for (i = 0; i < N; i++)
			memset(visited[i], 0, sizeof(bool) * N);
	}
	cout << ans << "\n";
}