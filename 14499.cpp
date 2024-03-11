#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// ���� 14499��: �ֻ��� ������ (��� 4)
int board[20][20];	// ������ �� ĭ ��ȣ ����
int dice[6];	// �ֻ��� �� �ڸ� ��ȣ ����
/*
	dice[0] = �ֻ��� �ظ�, dice[1] = �ֻ��� ����
	dice[2] = �ֻ��� ���ʸ�, dice[3] = �ֻ��� �����ʸ�
	dice[4] = �ֻ��� �ո�, dice[5] = �ֻ��� �޸�
*/
int N, M, x, y, K;
int move(int dir);	// ������ �� ������ �̵��ϰ� 1�� ����, �̵����� ���ϸ� ��ٷ� 0�� ���� (ȸ�� X)
void rotate(int dir);	// �ֻ��� ȸ��

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
		// �̵� ������ ���� ����� �����ϰ� �����
		if (move(dir)) {
			// �ֻ��� ȸ��
			rotate(dir);
			// ������ ���� ĭ�� 0�� �ƴ� ��
			if (board[x][y]) {
				dice[0] = board[x][y];	// ������ ���� ĭ ��ȣ�� �ֻ��� �ظ� ��ȣ�� ����
				board[x][y] = 0;	// ������ ���� ĭ 0���� ����
			}
			else
				board[x][y] = dice[0];	// �ֻ��� �ظ� ��ȣ�� ������ ���� ĭ���� ����
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