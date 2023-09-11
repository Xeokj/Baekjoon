#include <bits/stdc++.h>
using namespace std;
// virus: �Է����� ������ ���̷����� ��ǥ ����
// vacant: �Է����� ������ 0�� �κ� ��ǥ ����
/*
	[���� ����� ��Ŀ����]
	������ 3���� ���� ������ ��� ���� 0�̰� ������ 3�� ���� 1�� permu��� �迭��
	next_permutation �Լ��� ������ permu[i] = 1�� i�� ��� vacant[i]���� ��ǥ�� ����
	(�ش� ��ǥ�� �迭 wall�� ������)
	�׷� vacant���� 3���� ��ǥ�� �����Ƿ� �ش� ��ǥ �ڸ��� ���� ����
*/
vector<pair<int, int>> virus, vacant;
int board[8][8], temp[8][8], permu[64], wall[3][2];
// temp: board �迭 ���纻
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int N, M, v, empt, ans;
// v: �Է����� ������ ���̷����� ����
// empt: �Է����� ������ 0�� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, y, x;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				// 0�� ��ǥ ����
				vacant.push_back({ i,j });
				empt++;	// 0�� ���� 1 ����
			}
			if (board[i][j] == 2) {
				// ���̷��� ��ǥ ����
				virus.push_back({ i,j });
				v++;	// ���̷��� ���� 1 ����
			}
		}
	// next_permutation�� ���� �迭 ����� (�� 3���� 1�� ����)
	for (i = 1; i <= 3; i++)
		permu[empt - i] = 1;
	// next_permutation �Լ� ������
	do {
		// ���� ���� ����
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				temp[i][j] = board[i][j];
		int idx = 0, e = 0;
		while (e < 3) {
			if (permu[idx]) {
				// ���� �� �� ��ǥ ����
				wall[e][0] = vacant[idx].first;
				wall[e][1] = vacant[idx].second;
				e++;
			}
			idx++;
		}
		// ���� �� ���� �� �����
		for (e = 0; e < 3; e++)
			temp[wall[e][0]][wall[e][1]] = 1;
		int safe = empt - 3;	// ���� 0�� ������ ����
		// BFS ����
		queue<pair<int, int>> q;
		for (i = 0; i < v; i++)
			q.push(virus[i]);	// ���̷����� ��ǥ queue�� ����
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (!temp[ny][nx]) {
					// 0�� �κ����� ���̷��� ����
					temp[ny][nx] = 2;
					q.push({ ny,nx });
					safe--;	// �������� ���� 1 ����
				}
			}
		}
		if (safe > ans)
			ans = safe;
	} while (next_permutation(permu, permu + empt));
	cout << ans;
}