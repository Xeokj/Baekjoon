#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char arr[20][20];
int visited[26];	// ���ĺ�(A to Z)�� �湮 üũ
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
void DFS(int y, int x, int num);	// x,y: ��ǥ, num: �̵��� ĭ�� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			cin >> arr[i][j];
	DFS(0, 0, 1);	// ������ �����̹Ƿ� 1�� ����
	cout << ans;
}

void DFS(int y, int x, int num) {
	visited[arr[y][x] - 'A'] = 1;	// ���ĺ� �湮 üũ
	if (num > ans)
		ans = num;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			// ������ ���� �湮���� ���� ���ĺ��� �ִٸ� �̵�
			if (!visited[arr[ny][nx] - 'A'])
				DFS(ny, nx, num + 1);
		}
	}
	visited[arr[y][x] - 'A'] = 0;	// �湮 �� �� ������ �ʱ�ȭ
}