#include <bits/stdc++.h>
using namespace std;
// ���� 16236��: �Ʊ� ��� (��� 3)
int N, M, ans;
int cursize = 2, cury, curx, ate;
// ���� ����� ũ��, ����� ��ġ, �� ���� ������� ����
int board[20][20], visited[20][20];
int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };
int BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				cury = i;
				curx = j;
				board[i][j] = 0;
				// ���߿� �� �ִ� �ڸ��ε� �̵��� �� �ֵ��� 0���� �ٲ���
			}
		}
	while (1) {
		int sec = BFS();	// �� ���̷� �̵��ϴµ� �ɸ� �ð�
		ans += sec;	// ������
		if (!sec)	// ���̷� �̵����� ���ߴٸ� �ݺ����� ����
			break;
	}
	cout << ans;
}

int BFS() {
	for (int i = 0; i < N; i++)
		memset(visited[i], 0, sizeof(int) * N);
	int dist = 0;
	queue<pair<int, int>> q;
	// ����� �̵� ��θ� ������ ť
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// �� ���� �� �ִ� ������� ��ġ
	// pq���� ���� �� �ִ� ���������� �Ÿ��� �ִ� �Ÿ��� �͸� ��
	q.push({ cury,curx });
	visited[cury][curx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == dist)
			continue;	// ���̸� ���� �� �ִ� �ִ� �Ÿ����� Ŭ ��
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (!board[ny][nx] || board[ny][nx] == cursize) {
				// 0�̰ų� �ڱ� �ڽŰ� ���� ũ���� ���� ������ �� ����
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
			else if (board[ny][nx] < cursize) {
				// (ny,nx) ��ġ�� ���� �� �ִ� ����Ⱑ ���� ��
				if (!dist)
					ate++;	// �Ÿ��� Ȯ�����ٸ� ���� ������ �ø��� ����
				visited[ny][nx] = visited[y][x] + 1;
				dist = visited[ny][nx];	// �ּ� �Ÿ� Ȯ��
				pq.push({ ny,nx });	// �켱���� ť�� ����
			}
		}
	}
	if (pq.empty())
		return 0;
	cury = pq.top().first;
	curx = pq.top().second;
	// �켱 �������� ���� ���̸鼭 ���ʿ� ��ġ�� ��ǥ�� �̰�
	// �ش� ��ġ�� ������ �Ʊ� ����� ���� ��ġ�� ����
	board[cury][curx] = 0;	// �ش� ��ġ�� ���̸� �Ծ����Ƿ� 0���� ����
	if (ate == cursize) {
		// ���� Ƚ���� �Ʊ� ����� ũ��� ���� ��
		cursize++;
		ate = 0;
	}
	return visited[cury][curx] - 1;	// �̵� Ƚ�� ����
}