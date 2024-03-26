#include <bits/stdc++.h>
using namespace std;
// ���� 15683��: ���� (��� 4)
int board[8][8];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> CCTV;	// �� CCTV�� ��ǥ
int N, M, ans;
void backtr(int idx, int num);
int eliminate(int y, int x, int dir);	// �־��� ���⿡ ���� �� ĭ�� 1 ���ҽ�Ŵ
void recover(int y, int x, int dir);	// eliminate���� 1 ���� ���� ���󺹱� ��Ű���� 1 ������Ŵ

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	// �ʱ� �簢���� ������ N * M �̶�� �ʱ�ȭ
	ans = N * M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				// ���̰ų� CCTV�� ��� �簢���� �������� ��
				ans--;
				if (board[i][j] != 6) {
					// CCTV�� ��� CCTV ��ġ(��ǥ)�� ����
					CCTV.push_back({ i,j });
				}
			}
		}
	backtr(0, ans);
	cout << ans;
}

void backtr(int idx, int num) {
	// num: ���� �簢������ ����
	if (idx == CCTV.size()) {
		if (num < ans)
			ans = num;
		return;
	}
	int y = CCTV[idx].first;
	int x = CCTV[idx].second;
	int CCTV_type = board[y][x];
	int dir, cnt = 0;
	// cnt: ���� idx�� CCTV�� ������� �簢������ ���� 
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
	int zero = 0;	// 0�� ���� (���� �湮���� ���� �� ĭ�� ����)
	while (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 6) {
		// ������ ����ų� ���� ���� ������ ����
		if (board[ny][nx] == 0)
			zero++;	// ó�� �湮�ϴ� �� ĭ�� ��
		if (board[ny][nx] <= 0)	// �� ĭ�� ���
			board[ny][nx]--;	// �� ĭ�� ���� 1 ���ҽ�Ŵ
		// CCTV�� �ִ� ĭ�̸� ���� if���� �������� ����
		ny += dy[dir];
		nx += dx[dir];
	}
	return zero;
}

void recover(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	while (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 6) {
		if (board[ny][nx] < 0)	// �� ĭ�� ���
			board[ny][nx]++;
		ny += dy[dir];
		nx += dx[dir];
	}
}