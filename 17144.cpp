#include <bits/stdc++.h>
using namespace std;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int board_odd[50][50], board_even[50][50];
int R, C, T, up, down;
void transmit(int y, int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> T;
	int ans = 0, num, i, j;
	bool flg = 0;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> num;
			// T가 홀수면 odd, 짝수면 even에 저장
			if (T % 2)
				board_odd[i][j] = num;
			else
				board_even[i][j] = num;
			if (num == -1) {
				if (!flg) {
					up = i;
					down = i + 1;
					flg = 1;
				}
			}
		}
	}
	while (T--) {
		// T가 홀수면 even을 이용해 odd에 저장, 짝수면 odd를 이용해 even에 저장
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				// 전이
				if (T % 2 && board_even[i][j] > 0)
					transmit(i, j);
				else if (!(T % 2) && board_odd[i][j] > 0)
					transmit(i, j);
			}
		}
		// 회전
		if (T % 2) {
			// 반시계 방향
			for (i = up - 2; i >= 0; i--)
				board_odd[i + 1][0] = board_odd[i][0];
			for (j = 1; j < C; j++)
				board_odd[0][j - 1] = board_odd[0][j];
			for (i = 1; i < up + 1; i++)
				board_odd[i - 1][C - 1] = board_odd[i][C - 1];
			for (j = C - 2; j > 0; j--)
				board_odd[up][j + 1] = board_odd[up][j];
			board_odd[up][1] = 0;
			// 시계 방향
			for (i = down + 2; i < R; i++)
				board_odd[i - 1][0] = board_odd[i][0];
			for (j = 1; j < C; j++)
				board_odd[R - 1][j - 1] = board_odd[R - 1][j];
			for (i = R - 2; i > down - 1; i--)
				board_odd[i + 1][C - 1] = board_odd[i][C - 1];
			for (j = C - 2; j > 0; j--)
				board_odd[down][j + 1] = board_odd[down][j];
			board_odd[down][1] = 0;
		}
		else {
			// 반시계 방향
			for (i = up - 2; i >= 0; i--)
				board_even[i + 1][0] = board_even[i][0];
			for (j = 1; j < C; j++)
				board_even[0][j - 1] = board_even[0][j];
			for (i = 1; i < up + 1; i++)
				board_even[i - 1][C - 1] = board_even[i][C - 1];
			for (j = C - 2; j > 0; j--)
				board_even[up][j + 1] = board_even[up][j];
			board_even[up][1] = 0;
			// 시계 방향
			for (i = down + 2; i < R; i++)
				board_even[i - 1][0] = board_even[i][0];
			for (j = 1; j < C; j++)
				board_even[R - 1][j - 1] = board_even[R - 1][j];
			for (i = R - 2; i > down - 1; i--)
				board_even[i + 1][C - 1] = board_even[i][C - 1];
			for (j = C - 2; j > 0; j--)
				board_even[down][j + 1] = board_even[down][j];
			board_even[down][1] = 0;
		}
		// 0으로 초기화
		if (T % 2) {
			for (i = 0; i < R; i++)
				memset(board_even[i], 0, sizeof(int) * C);
		}
		else {
			for (i = 0; i < R; i++)
				memset(board_odd[i], 0, sizeof(int) * C);
		}
	}
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			if (board_even[i][j] > 0)
				ans += board_even[i][j];
	cout << ans;
}

void transmit(int y, int x) {
	if (T % 2)
		board_odd[y][x] += board_even[y][x];
	else
		board_even[y][x] += board_odd[y][x];
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;
		if ((ny == up && nx == 0) || (ny == down && nx == 0))
			continue;
		if (T % 2)
			board_odd[ny][nx] += (board_even[y][x] / 5);
		else
			board_even[ny][nx] += (board_odd[y][x] / 5);
		cnt++;
	}
	if (T % 2)
		board_odd[y][x] -= ((board_even[y][x] / 5) * cnt);
	else
		board_even[y][x] -= ((board_odd[y][x] / 5) * cnt);
}