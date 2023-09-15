#include <bits/stdc++.h>
using namespace std;
// 백준 16236번: 아기 상어 (골드 3)
int N, M, ans;
int cursize = 2, cury, curx, ate;
// 현재 상어의 크기, 상어의 위치, 상어가 먹은 물고기의 개수
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
				// 나중에 상어가 있는 자리로도 이동할 수 있도록 0으로 바꿔줌
			}
		}
	while (1) {
		int sec = BFS();	// 상어가 먹이로 이동하는데 걸린 시간
		ans += sec;	// 더해줌
		if (!sec)	// 먹이로 이동하지 못했다면 반복문을 끝냄
			break;
	}
	cout << ans;
}

int BFS() {
	for (int i = 0; i < N; i++)
		memset(visited[i], 0, sizeof(int) * N);
	int dist = 0;
	queue<pair<int, int>> q;
	// 상어의 이동 경로를 저장한 큐
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 상어가 먹을 수 있는 물고기의 위치
	// pq에는 먹을 수 있는 물고기까지의 거리가 최단 거리인 것만 들어감
	q.push({ cury,curx });
	visited[cury][curx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == dist)
			continue;	// 먹이를 먹을 수 있는 최단 거리보다 클 때
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (!board[ny][nx] || board[ny][nx] == cursize) {
				// 0이거나 자기 자신과 같은 크기인 곳은 지나갈 수 있음
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
			else if (board[ny][nx] < cursize) {
				// (ny,nx) 위치에 먹을 수 있는 물고기가 있을 때
				if (!dist)
					ate++;	// 거리가 확정났다면 먹은 개수를 늘리지 않음
				visited[ny][nx] = visited[y][x] + 1;
				dist = visited[ny][nx];	// 최소 거리 확정
				pq.push({ ny,nx });	// 우선순위 큐에 넣음
			}
		}
	}
	if (pq.empty())
		return 0;
	cury = pq.top().first;
	curx = pq.top().second;
	// 우선 순위에서 가장 위이면서 왼쪽에 위치한 좌표를 뽑고
	// 해당 위치를 다음번 아기 상어의 시작 위치로 지정
	board[cury][curx] = 0;	// 해당 위치의 먹이를 먹었으므로 0으로 만듦
	if (ate == cursize) {
		// 먹은 횟수가 아기 상어의 크기와 같을 때
		cursize++;
		ate = 0;
	}
	return visited[cury][curx] - 1;	// 이동 횟수 리턴
}