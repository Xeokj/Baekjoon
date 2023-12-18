#include <bits/stdc++.h>
using namespace std;
// ���� 16234��: �α� �̵� (��� 4)
int board[50][50];
bool visited[50][50];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, L, R, i, j, ans = 0;
	cin >> N >> L >> R;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> board[i][j];
	bool flg = 1;	// �α� �̵��� �Ͼ���� ǥ��
	while (flg) {
		flg = 0;	// �α� �̵��� �Ͼ�� �ʴ´ٰ� ����
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				// ���� �湮���� ���� ���� �������� BFS Ž��
				if (!visited[i][j]) {
					queue<pair<int, int>> q;	// BFS�� ����� ť
					queue<pair<int, int>> coord;	// �α� �̵��� �Ͼ�� ��ǥ�� ����
					q.push({ i,j });
					coord.push({ i,j });
					visited[i][j] = 1;
					int area = 1;	// �湮�� ����(��ǥ)�� ���� (������ �̷�� �ִ� ĭ�� ����)
					int sum = board[i][j];	// ������ �α���
					while (!q.empty()) {
						int cury = q.front().first;
						int curx = q.front().second;
						q.pop();
						int curp = board[cury][curx];
						for (int dir = 0; dir < 4; dir++) {
							int ny = cury + dy[dir];
							int nx = curx + dx[dir];
							if (ny < 0 || ny >= N || nx < 0 || nx >= N)
								continue;
							// ���漱�� �� �� ���� ��
							if (abs(board[ny][nx] - curp) >= L && abs(board[ny][nx] - curp) <= R && !visited[ny][nx]) {
								q.push({ ny,nx });
								coord.push({ ny,nx });
								area++;
								sum += board[ny][nx];
								visited[ny][nx] = 1;
							}
						}
					}
					// area�� 2 �̻��̸� �α� �̵��� �Ͼ���Ƿ� flg�� 1�� �ٲ���
					if (area > 1)
						flg = 1;
					int np = sum / area;	// �α� �̵��� �Ͼ ���� �� ���� �α���
					while (!coord.empty()) {
						int y = coord.front().first;
						int x = coord.front().second;
						coord.pop();
						board[y][x] = np;	// �α��� ������Ʈ
					}
				}
			}
		}
		if (flg)
			ans++;	// �α� �̵��� �Ͼ�� ���
		// visited�� ��� 0���� �ʱ�ȭ
		for (i = 0; i < N; i++)
			memset(visited[i], 0, sizeof(bool) * N);
	}
	cout << ans << "\n";
}