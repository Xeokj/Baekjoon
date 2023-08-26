#include <bits/stdc++.h>
using namespace std;
int N;
int board[20][20], emptys[20][20], prefer[401][4];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
// board: ������ �ڸ�
// emptys: ����ִ� ĭ�� ���� (empty seats)
// prefer: �� �л����� ��ȣ ��ȣ ����
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
	// �� �ڸ����� �ش� �л��� ������ ĭ�� ���� �����ϴ� �л��� ���� �ľ��� ������ ����
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int cnt = 0;	// ������ ĭ�� ���� �л� �� �����ϴ� �л��� ��
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
	// ������
	emptys[0][0] = 2;
	emptys[0][N - 1] = 2;
	emptys[N - 1][0] = 2;
	emptys[N - 1][N - 1] = 2;
	for (int i = 1; i < N - 1; i++) {
		emptys[0][i] = 3;	// ���� �𼭸�
		emptys[N - 1][i] = 3;	// �Ʒ��� �𼭸�
		emptys[i][0] = 3;	// ���� �𼭸�
		emptys[i][N - 1] = 3;	// ������ �𼭸�
		for (int j = 1; j < N - 1; j++)
			emptys[i][j] = 4;	// ����
	}
}

void find_seat(int student) {
	int i, j, k, max = -1;	// ������ �ڸ��� �ִ� �����ϴ� �л��� �� �ִ�
	int y, x, emptyseat;
	// y, x : ��ġ�� �ڸ��� �ĺ� ��ǥ
	// emptyseat: �ĺ� ��ǥ���� ������ �ڸ� �� ����ִ� ���� ����
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			// �̹� �ڸ��� �ִ� ���� pass
			if (board[i][j])
				continue;
			int cnt = 0;	// ������ �ڸ��� �����ϴ� �л��� �� ���� �ִ���
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
				// ������ �ڸ����� ������ �ڸ��� �����ϴ� �л��� ���� �� ���� ��
				max = cnt;
				// �ĺ� �ڸ� ���� ����
				y = i;
				x = j;
				emptyseat = emptys[y][x];
			}
			else if (cnt == max) {
				// ������ �ڸ��� �ִ� �����ϴ� �л��� ���� ���� �ĺ� �ڸ��� ���� ���
				// ������ �ڸ� �� ����ִ� �ڸ��� �� ���� �� �ĺ� ���� ����
				if (emptys[i][j] > emptyseat) {
					y = i;
					x = j;
					emptyseat = emptys[y][x];
				}
			}
		}
	}
	board[y][x] = student;	// �ڸ� Ȯ��
	// ������ ĭ�� emptys �ϳ��� ���ҽ�Ű��
	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		emptys[ny][nx]--;
	}
}