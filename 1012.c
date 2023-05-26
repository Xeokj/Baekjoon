#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M, K;
void BFS(int** map, int** visited, int i, int j);

typedef struct _Queue {
	int y;
	int x;
} Queue;

int main() {
	int T, cnt, i, j;	// cnt: 지렁이의 마리 수
	scanf("%d", &T);

	while (T) {
		scanf("%d %d %d", &M, &N, &K);
		int** map = (int**)calloc(N + 1, sizeof(int*));
		int** visited = (int**)calloc(N + 1, sizeof(int*));
		for (i = 0; i < N; i++) {
			map[i] = (int*)calloc(M + 1, sizeof(int*));
			visited[i] = (int*)calloc(M + 1, sizeof(int*));
		}

		int Y, X;
		for (i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			map[Y][X] = 1;
		}
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					BFS(map, visited, i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		for (i = 0; i < N; i++) {
			free(map[i]);
			free(visited[i]);
		}
		free(map);
		free(visited);
		T--;
	}
	return 0;
}

void BFS(int** map, int** visited, int i, int j) {
	Queue* q = (Queue*)calloc(K, sizeof(Queue));
	q[0].y = i, q[0].x = j;

	int front = -1, rear = 0;
	int dir, ny, nx;

	while (front < rear) {
		front++;
		for (dir = 0; dir < 4; dir++) {
			ny = q[front].y + dy[dir];
			nx = q[front].x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (map[ny][nx] && !visited[ny][nx]) {
				rear++;
				q[rear].y = ny;
				q[rear].x = nx;
				visited[ny][nx] = 1;
			}
		}
	}
	free(q);
}