#include <bits/stdc++.h>
using namespace std;

int board[100][100];	// find_hole�� return_to_org �Լ��� ���� ���� ����� -1�� ǥ��
int visited[100][100];	// �湮�� �ϸ� visited�� 1�� �����, ġ���� ��� �ֺ� ������ ������ŭ �߰��� ����
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M, flag;	// flag�� �ܺ� �������� ���� �������� �ľ��ϴ� �뵵
vector<pair<int, int>> zero;	// ���� �κ��� ��ǥ�� ����
void find_hole(int y, int x);	// ���� �κ��� �ϴ� -1�� �ٲ�
void return_to_org();	// �ܺ� ����� �ٽ� 0���� �ٲ�
void find_cheese(int y, int x);	// �Ϲ� BFS�� ���� ����

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
		int flag_ch = 0;	// ġ� ������ 1, ������ 0
		// ���� ã��: ���⼭ visited�� 0�� �� �湮�� ǥ��
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (board[i][j])
					flag_ch = 1;
				else if (!board[i][j] && !visited[i][j]) {
					find_hole(i, j);
					if (flag) {
						// ������ �ƴ� ��� ���� ����
						return_to_org();
						flag = 0;
					}
					zero.clear();
				}
			}
		}
		// ��� 0�̸� ����
		if (!flag_ch)
			break;
		else
			hour++;
		memset(visited, 0, sizeof(visited));
		// ġ�� ã��: ���⼭ visited�� 1�� �� �湮�� ǥ��
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < M - 1; j++) {
				if (board[i][j] == 1 && !visited[i][j])
					find_cheese(i, j);
			}
		}
		// visited�� 3 �̻��� ���� �� �� �̻� ����� ������ ��
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
				flag = 1;	// ���� ������ �Ѿ�� �ܺ� ����
		}
	}
}

void return_to_org() {
	int size = zero.size(), i, y, x;
	// �ܺ� �����̹Ƿ� 0���� ���� ����
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
				// 0�̸� ������ �ƴ� �����̹Ƿ� visited ����
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