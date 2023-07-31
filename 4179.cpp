#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char arr[1000][1000];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue<pair<pair<int, int>, int>> q;
// q���� first�� F�Ǵ� J�� ��ǥ, second�� J�� �ð� (�ð��� 1���� ����)
// ���� second�� 0�̸� F, 1 �̻��̸� J 
// J�� �׵θ��� �ٴٸ��� BFS�� ������
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	int i, j, jy, jx;
	// �� �ð����� ���� ���� ���� �� �����̰� �������� �ϹǷ�
	// �Է��� ������ F�� ���� queue�� �־���
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				jy = i;
				jx = j;
			}
			else if (arr[i][j] == 'F')
				q.push(make_pair(make_pair(i, j), 0));
		}
	// J�� queue�� �־��ְ�, �ð��� 1���� ����
	q.push(make_pair(make_pair(jy, jx), 1));
	BFS();
	if (ans)
		cout << ans;
	else
		cout << "IMPOSSIBLE";
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if ((y == 0 || y == R - 1 || x == 0 || x == C - 1) && t) {
			ans = t;
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
				// t�� 1�̻��̸� J, 0�̸� F
				if (t) {
					if (arr[ny][nx] == '.') {
						// J�� �̵���θ� �����ϱ� ���� J�� �ٲ���
						arr[ny][nx] = 'J';
						// �ð� 1 �����ؼ� queue�� ����
						q.push(make_pair(make_pair(ny, nx), t + 1));
					}
				}
				else {
					if (arr[ny][nx] == '.' || arr[ny][nx] == 'J') {
						// F�� �̵��� ��ġ�� F�� �ٲ���
						arr[ny][nx] = 'F';
						q.push(make_pair(make_pair(ny, nx), 0));
					}
				}
			}
		}
	}
}