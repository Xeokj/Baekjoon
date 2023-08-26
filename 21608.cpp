#include <bits/stdc++.h>
using namespace std;
int N;
int board[20][20], emptys[20][20], prefer[401][4];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
// board: 배정할 자리
// emptys: 비어있는 칸의 개수 (empty seats)
// prefer: 각 학생들의 선호 번호 저장
void emptys_init();
void find_seat(int student);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	emptys_init();
	int student, i, j, k;
	for (i = 0; i < N * N; i++) {
		cin >> student;
		for (j = 0; j < 4; j++) {
			cin >> prefer[student][j];
		}
		find_seat(student);
	}
	int ans = 0;
	// 각 자리별로 해당 학생과 인접한 칸에 앉은 좋아하는 학생의 수를 파악해 만족도 조사
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int cnt = 0;	// 인접한 칸에 앉은 학생 중 좋아하는 학생의 수
			for (int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				for (k = 0; k < 4; k++) {
					if (board[ny][nx] == prefer[board[i][j]][k]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt == 1)
				ans++;
			else if (cnt == 2)
				ans += 10;
			else if (cnt == 3)
				ans += 100;
			else if (cnt == 4)
				ans += 1000;
		}
	}
	cout << ans;
}

void emptys_init() {
	// 꼭지점
	emptys[0][0] = 2;
	emptys[0][N - 1] = 2;
	emptys[N - 1][0] = 2;
	emptys[N - 1][N - 1] = 2;
	for (int i = 1; i < N - 1; i++) {
		emptys[0][i] = 3;	// 위쪽 모서리
		emptys[N - 1][i] = 3;	// 아래쪽 모서리
		emptys[i][0] = 3;	// 왼쪽 모서리
		emptys[i][N - 1] = 3;	// 오른쪽 모서리
		for (int j = 1; j < N - 1; j++)
			emptys[i][j] = 4;	// 안쪽
	}
}

void find_seat(int student) {
	int i, j, k, max = -1;	// 인접한 자리에 있는 좋아하는 학생의 수 최댓값
	int y, x, emptyseat;
	// y, x : 배치할 자리의 후보 좌표
	// emptyseat: 후보 좌표에서 인접한 자리 중 비어있는 곳의 개수
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			// 이미 자리가 있는 경우는 pass
			if (board[i][j])
				continue;
			int cnt = 0;	// 인접한 자리에 좋아하는 학생이 몇 명이 있는지
			for (int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				for (k = 0; k < 4; k++) {
					if (board[ny][nx] == prefer[student][k]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt > max) {
				// 현재의 자리에서 인접한 자리에 좋아하는 학생의 수가 더 많을 때
				max = cnt;
				// 후보 자리 새로 갱신
				y = i;
				x = j;
				emptyseat = emptys[y][x];
			}
			else if (cnt == max) {
				// 인접한 자리에 있는 좋아하는 학생의 수가 기존 후보 자리와 같은 경우
				// 인접한 자리 중 비어있는 자리가 더 많을 때 후보 새로 갱신
				if (emptys[i][j] > emptyseat) {
					y = i;
					x = j;
					emptyseat = emptys[y][x];
				}
			}
		}
	}
	board[y][x] = student;	// 자리 확정
	// 인접한 칸들 emptys 하나씩 감소시키기
	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		emptys[ny][nx]--;
	}
}