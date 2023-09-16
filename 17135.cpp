#include <bits/stdc++.h>
using namespace std;
// ���� 17135��: ĳ�� ���潺 (��� 3)
int N, M, D, enm, remains, removed, ans;
int origin[16][15], temp[16][15], visited[16][15], arr[15];
// arr: �ü� ��ġ�� �ϱ� ���� next_permutation�� ���� �迭
int target[3][2];	// ���� ���� ��ġ�� ����
int dy[3] = { -1,0,0}, dx[3] = { 0,-1,1};
void targeting(int x, int idx);	// ���� ���� ��ġ�� ã�� �Լ�
void GoDown();	// �Ʒ��� �� ĭ�� ������ �Լ�

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M >> D;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			cin >> origin[i][j];
			if (origin[i][j])
				enm++;	// ���� �� ����
		}
	for (i = 1; i <= 3; i++)
		arr[M - i] = 1;	// next_permutation �Լ� ���� �迭 (�ü� ��ġ)
	do {
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				temp[i][j] = origin[i][j];
		// temp �ʱ�ȭ
		for (j = 0; j < M; j++)
			temp[N][j] = arr[j];	// �ü� ��ġ�� �� temp�� �ű��
		remains = enm;	// �����ִ� ���� ��
		removed = 0;	// ���� ���� ��
		while (remains) {	// �����ִ� ���� ���� ������
			for (i = 0; i < 3; i++) {
				target[i][0] = -1;
				target[i][1] = -1;
				// ���� ���� ��ġ�� ������ �迭 �ʱ�ȭ
			}
			int idx = 0;
			for (j = 0; j < M; j++)
				if (temp[N][j]) {
					// �ü��� �ִ� ��ġ���� BFS Ž�� ����
					targeting(j, idx);
					idx++;	// ���� ���� ��ġ�� ������ target �迭�� index ����
				}
			for (i = 0; i < 3; i++) {
				int y = target[i][0];
				int x = target[i][1];
				if (y == -1 && x == -1)
					continue;	// �ش� ���ʶ� ���� �� �ִ� ���� �߰����� ���� ���
				if (temp[y][x]) {
					// ���� �ٸ� �ü��� ���� ���� ��ǥ�� �� �� �־ if�� ������ ��
					temp[y][x] = 0;	// �ش� ��ġ �� ����
					removed++;	// ���� ���� �� 1 ����
					remains--;	// �����ִ� ���� �� 1 ����
				}
			}
			GoDown();	// �Ʒ��� �� ĭ�� �������� ����
		}
		if (removed > ans)
			ans = removed;
	} while (next_permutation(arr, arr + M));

	cout << ans;
}

void targeting(int x, int idx) {
	for (int i = 0; i <= N; i++)
		memset(visited[i], 0, sizeof(int) * M);
	int dist = 0;	// ���� ������ �ִ� ���� �Ÿ�
	queue<pair<int, int>> q;
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// �� ���� ��ǥ�� ������ ���� (��, ��)���� �־���
	q.push({ N,x });
	visited[N][x] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == dist || visited[y][x] > D)
			break;	// �� �� �ִ� ���� ã�� ���� or D�� ��� ����
		for (int dir = 0; dir < 3; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (visited[ny][nx])
				continue;
			if (!temp[ny][nx]) {
				// �ش� ��ġ�� ���� ���� ��
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
			else if (temp[ny][nx]) {
				// ���� ���� ��
				visited[ny][nx] = visited[y][x] + 1;
				dist = visited[ny][nx];	// �ּ� �Ÿ� Ȯ��
				pq.push({ nx,ny });	// �켱���� ť�� ����
			}
		}
	}
	if (pq.empty())
		return;	// �� �� �ִ� ���� ���� ���
	target[idx][0] = pq.top().second;	// ���� y ��ǥ
	target[idx][1] = pq.top().first;	// ���� x ��ǥ
}

void GoDown() {
	int i, j;
	// ���� �ٷ� �տ� �ִ� ������ ���� ����
	for (j = 0; j < M; j++)
		if (temp[N - 1][j])
			remains--;
	// �Ʒ��� �� ĭ�� ������
	for (i = N - 2; i >= 0; i--) {
		for (j = 0; j < M; j++) {
			temp[i + 1][j] = temp[i][j];
		}
	}
	for (j = 0; j < M; j++)
		temp[0][j] = 0;
}