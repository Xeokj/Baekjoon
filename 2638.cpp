#include <bits/stdc++.h>
using namespace std;

int board[100][100];	// find_hole과 return_to_org 함수를 통해 내부 공기는 -1로 표시
int visited[100][100];	// 방문을 하면 visited를 1로 만들고, 치즈의 경우 주변 공기의 개수만큼 추가로 증가
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M, flag;	// flag는 외부 공기인지 내부 공기인지 파악하는 용도
vector<pair<int, int>> zero;	// 공기 부분의 좌표를 저장
void find_hole(int y, int x);	// 공기 부분은 일단 -1로 바꿈
void return_to_org();	// 외부 공기면 다시 0으로 바꿈
void find_cheese(int y, int x);	// 일반 BFS와 같은 형태

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int hour = 0, i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	while (1) {
		int flag_ch = 0;	// 치즈가 있으면 1, 없으면 0
		// 구멍 찾기: 여기서 visited는 0인 곳 방문을 표시
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (board[i][j])
					flag_ch = 1;
				else if (!board[i][j] && !visited[i][j]) {
					find_hole(i, j);
					if (flag) {
						// 구멍이 아닌 경우 원상 복귀
						return_to_org();
						flag = 0;
					}
					zero.clear();
				}
			}
		}
		// 모두 0이면 종료
		if (!flag_ch)
			break;
		else
			hour++;
		memset(visited, 0, sizeof(visited));
		// 치즈 찾기: 여기서 visited는 1인 곳 방문을 표시
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (board[i][j] == 1 && !visited[i][j])
					find_cheese(i, j);
			}
		}
		// visited가 3 이상인 곳은 두 곳 이상 공기와 접촉한 곳
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (visited[i][j] > 2)
					board[i][j] = 0;
				if (board[i][j] == -1)
					board[i][j] = 0;
			}
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << hour;
}

void find_hole(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y,x));
	zero.push_back(make_pair(y, x));
	board[y][x] = -1;
	visited[y][x] = 1;
	while (!q.empty()) {
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = qy + dy[dir];
			int nx = qx + dx[dir];
			if (ny >= 1 && ny < N - 1 && nx >= 1 && nx < M - 1) {
				if (!board[ny][nx] && !visited[ny][nx]) {
					board[ny][nx] = -1;
					zero.push_back(make_pair(ny, nx));
					q.push(make_pair(ny, nx));
					visited[ny][nx] = 1;
				}
			}
			else
				flag = 1;	// 위의 범위를 넘어가면 외부 공기
		}
	}
}

void return_to_org() {
	int size = zero.size(), i, y, x;
	// 외부 공기이므로 0으로 원상 복귀
	for (i = 0; i < size; i++) {
		y = zero[i].first;
		x = zero[i].second;
		board[y][x] = 0;
	}
}

void find_cheese(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = qy + dy[dir];
			int nx = qx + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				// 0이면 구멍이 아닌 공기이므로 visited 증가
				if (!board[ny][nx])
					visited[qy][qx]++;
				else if (board[ny][nx] == 1 && !visited[ny][nx]) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = 1;
				}
			}
		}
	}
}