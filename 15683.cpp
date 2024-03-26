#include <bits/stdc++.h>
using namespace std;
// 백준 15683번: 감시 (골드 4)
int board[8][8];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> CCTV;	// 각 CCTV의 좌표
int N, M, ans;
void backtr(int idx, int num);
int eliminate(int y, int x, int dir);	// 주어진 방향에 따라 빈 칸을 1 감소시킴
void recover(int y, int x, int dir);	// eliminate에서 1 뺐던 것을 원상복구 시키도록 1 증가시킴

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	// 초기 사각지대 개수는 N * M 이라고 초기화
	ans = N * M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				// 벽이거나 CCTV인 경우 사각지대 개수에서 뺌
				ans--;
				if (board[i][j] != 6) {
					// CCTV인 경우 CCTV 위치(좌표)를 저장
					CCTV.push_back({ i,j });
				}
			}
		}
	backtr(0, ans);
	cout << ans;
}

void backtr(int idx, int num) {
	// num: 남은 사각지대의 개수
	if (idx == CCTV.size()) {
		if (num < ans)
			ans = num;
		return;
	}
	int y = CCTV[idx].first;
	int x = CCTV[idx].second;
	int CCTV_type = board[y][x];
	int dir, cnt = 0;
	// cnt: 현재 idx의 CCTV로 사라지는 사각지대의 개수 
	if (CCTV_type == 1) {
		for (dir = 0; dir < 4; dir++) {
			cnt = eliminate(y, x, dir);
			backtr(idx + 1, num - cnt);
			recover(y, x, dir);
		}
	}
	else if (CCTV_type == 2) {
		for (dir = 0; dir < 2; dir++) {
			cnt = eliminate(y, x, dir);
			cnt += eliminate(y, x, dir + 2);
			backtr(idx + 1, num - cnt);
			recover(y, x, dir);
			recover(y, x, dir + 2);
		}
	}
	else if (CCTV_type == 3) {
		for (dir = 0; dir < 4; dir++) {
			cnt = eliminate(y, x, dir);
			cnt += eliminate(y, x, (dir + 1) % 4);
			backtr(idx + 1, num - cnt);
			recover(y, x, dir);
			recover(y, x, (dir + 1) % 4);
		}
	}
	else if (CCTV_type == 4) {
		for (dir = 0; dir < 4; dir++) {
			cnt = eliminate(y, x, dir);
			cnt += eliminate(y, x, (dir + 1) % 4);
			cnt += eliminate(y, x, (dir + 2) % 4);
			backtr(idx + 1, num - cnt);
			recover(y, x, dir);
			recover(y, x, (dir + 1) % 4);
			recover(y, x, (dir + 2) % 4);
		}
	}
	else if (CCTV_type == 5) {
		for (dir = 0; dir < 4; dir++)
			cnt += eliminate(y, x, dir);
		backtr(idx + 1, num - cnt);
		for (dir = 0; dir < 4; dir++)
			recover(y, x, dir);
	}
}

int eliminate(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	int zero = 0;	// 0의 개수 (아직 방문하지 않은 빈 칸의 개수)
	while (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 6) {
		// 범위를 벗어나거나 벽을 만날 때까지 진행
		if (board[ny][nx] == 0)
			zero++;	// 처음 방문하는 빈 칸일 때
		if (board[ny][nx] <= 0)	// 빈 칸인 경우
			board[ny][nx]--;	// 빈 칸의 숫자 1 감소시킴
		// CCTV가 있는 칸이면 위의 if문을 실행하지 않음
		ny += dy[dir];
		nx += dx[dir];
	}
	return zero;
}

void recover(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	while (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 6) {
		if (board[ny][nx] < 0)	// 빈 칸인 경우
			board[ny][nx]++;
		ny += dy[dir];
		nx += dx[dir];
	}
}