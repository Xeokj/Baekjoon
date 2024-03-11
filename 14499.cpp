#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 14499번: 주사위 굴리기 (골드 4)
int board[20][20];	// 지도의 각 칸 번호 저장
int dice[6];	// 주사위 각 자리 번호 저장
/*
	dice[0] = 주사위 밑면, dice[1] = 주사위 윗면
	dice[2] = 주사위 왼쪽면, dice[3] = 주사위 오른쪽면
	dice[4] = 주사위 앞면, dice[5] = 주사위 뒷면
*/
int N, M, x, y, K;
int move(int dir);	// 움직일 수 있으면 이동하고 1을 리턴, 이동하지 못하면 곧바로 0을 리턴 (회전 X)
void rotate(int dir);	// 주사위 회전

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, dir;
	cin >> N >> M >> x >> y >> K;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	for (i = 0; i < K; i++) {
		cin >> dir;
		// 이동 가능할 때만 명령을 수행하고 출력함
		if (move(dir)) {
			// 주사위 회전
			rotate(dir);
			// 지도의 현재 칸이 0이 아닐 때
			if (board[x][y]) {
				dice[0] = board[x][y];	// 지도의 현재 칸 번호를 주사위 밑면 번호로 복사
				board[x][y] = 0;	// 지도의 현재 칸 0으로 지움
			}
			else
				board[x][y] = dice[0];	// 주사위 밑면 번호를 지도의 현재 칸으로 복사
			cout << dice[1] << "\n";
		}
	}
}

int move(int dir) {
	if (dir == 1 &&  y + 1 < M) {
		y++;
		return 1;
	}
	else if (dir == 2 && y - 1 >= 0) {
		y--;
		return 1;
	}
	else if (dir == 3 && x - 1 >= 0) {
		x--;
		return 1;
	}
	else if (dir == 4 && x + 1 < N) {
		x++;
		return 1;
	}
	return 0;
}

void rotate(int dir) {
	int tmp = dice[0];
	if (dir == 1) {
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	else if (dir == 2) {
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 3) {
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
	else if (dir == 4) {
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
}