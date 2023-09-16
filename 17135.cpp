#include <bits/stdc++.h>
using namespace std;
// 백준 17135번: 캐슬 디펜스 (골드 3)
int N, M, D, enm, remains, removed, ans;
int origin[16][15], temp[16][15], visited[16][15], arr[15];
// arr: 궁수 배치를 하기 위해 next_permutation을 돌릴 배열
int target[3][2];	// 죽일 적의 위치를 저장
int dy[3] = { -1,0,0}, dx[3] = { 0,-1,1};
void targeting(int x, int idx);	// 죽일 적의 위치를 찾는 함수
void GoDown();	// 아래로 한 칸씩 내리는 함수

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
				enm++;	// 적의 수 세기
		}
	for (i = 1; i <= 3; i++)
		arr[M - i] = 1;	// next_permutation 함수 돌릴 배열 (궁수 배치)
	do {
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				temp[i][j] = origin[i][j];
		// temp 초기화
		for (j = 0; j < M; j++)
			temp[N][j] = arr[j];	// 궁수 배치한 것 temp에 옮기기
		remains = enm;	// 남아있는 적의 수
		removed = 0;	// 죽인 적의 수
		while (remains) {	// 남아있는 적이 없을 때까지
			for (i = 0; i < 3; i++) {
				target[i][0] = -1;
				target[i][1] = -1;
				// 죽일 적의 위치를 저장할 배열 초기화
			}
			int idx = 0;
			for (j = 0; j < M; j++)
				if (temp[N][j]) {
					// 궁수가 있는 위치에서 BFS 탐색 시작
					targeting(j, idx);
					idx++;	// 죽일 적의 위치를 저장할 target 배열의 index 증가
				}
			for (i = 0; i < 3; i++) {
				int y = target[i][0];
				int x = target[i][1];
				if (y == -1 && x == -1)
					continue;	// 해당 차례때 죽일 수 있는 적을 발견하지 못한 경우
				if (temp[y][x]) {
					// 서로 다른 궁수가 같은 적을 목표로 할 수 있어서 if로 조건을 걺
					temp[y][x] = 0;	// 해당 위치 적 없앰
					removed++;	// 죽인 적의 수 1 증가
					remains--;	// 남아있는 적의 수 1 감소
				}
			}
			GoDown();	// 아래로 한 칸씩 내려오는 과정
		}
		if (removed > ans)
			ans = removed;
	} while (next_permutation(arr, arr + M));

	cout << ans;
}

void targeting(int x, int idx) {
	for (int i = 0; i <= N; i++)
		memset(visited[i], 0, sizeof(int) * M);
	int dist = 0;	// 가장 가까이 있는 적의 거리
	queue<pair<int, int>> q;
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 맨 왼쪽 좌표를 꺼내기 위해 (열, 행)으로 넣어줌
	q.push({ N,x });
	visited[N][x] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == dist || visited[y][x] > D)
			break;	// 쏠 수 있는 적을 찾은 상태 or D를 벗어난 상태
		for (int dir = 0; dir < 3; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (visited[ny][nx])
				continue;
			if (!temp[ny][nx]) {
				// 해당 위치에 적이 없을 때
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
			else if (temp[ny][nx]) {
				// 적이 있을 때
				visited[ny][nx] = visited[y][x] + 1;
				dist = visited[ny][nx];	// 최소 거리 확정
				pq.push({ nx,ny });	// 우선순위 큐에 넣음
			}
		}
	}
	if (pq.empty())
		return;	// 쏠 수 있는 적이 없는 경우
	target[idx][0] = pq.top().second;	// 적의 y 좌표
	target[idx][1] = pq.top().first;	// 적의 x 좌표
}

void GoDown() {
	int i, j;
	// 성벽 바로 앞에 있는 적들의 개수 세기
	for (j = 0; j < M; j++)
		if (temp[N - 1][j])
			remains--;
	// 아래로 한 칸씩 내리기
	for (i = N - 2; i >= 0; i--) {
		for (j = 0; j < M; j++) {
			temp[i + 1][j] = temp[i][j];
		}
	}
	for (j = 0; j < M; j++)
		temp[0][j] = 0;
}