#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Queue {
	int y;
	int x;
} Queue;

Queue q[10000];
int N, M;
int map[300][300];
int visited[300][300];
int water[300][300];	// 맞닿아 있는 물의 개수
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void BFS(int y, int x);
void IsWater(int y, int x);	// map[y][x]의 상하좌우에 물이 몇 개 있는지 파악

int main() {
	scanf("%d %d", &N, &M);

	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int cnt, year = 0;	// cnt: 빙산의 개수
	while (1) {
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		if (cnt > 1) {
			printf("%d", year);
			break;
		}
		else if (cnt == 0) {
			printf("0");
			break;
		}
		year++;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				// map에서 맞닿아 있는 물의 개수를 빼주고, 값이 음수가 되면 0으로 해줌
				if ((map[i][j] -= water[i][j]) < 0)
					map[i][j] = 0;
			}
		}
		// 다음 year를 계산하기 위해 water과 visited를 0으로 초기화
		for (i = 0; i < N; i++) {
			memset(water[i], 0, sizeof(int) * M);
			memset(visited[i], 0, sizeof(int) * M);
		}
	}
	return 0;
}

void BFS(int y, int x) {
	int front = -1, rear = 0;
	q[rear].y = y;
	q[rear].x = x;
	visited[y][x] = 1;
	IsWater(y, x);	// 주변에 물이 몇 개 있는지
	while (front < rear) {
		front++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (!visited[ny][nx] && map[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = 1;
					IsWater(ny, nx);
				}
			}
		}
	}
}

void IsWater(int y, int x) {
	for (int adj = 0; adj < 4; adj++) {
		int adjy = y + dy[adj];
		int adjx = x + dx[adj];
		if (adjy >= 0 && adjy < N && adjx >= 0 && adjx < M) {
			if (!map[adjy][adjx]) {
				water[y][x]++;
			}
		}
	}
}