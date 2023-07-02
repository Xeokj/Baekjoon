#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Queue {
	int y;
	int x;
} Queue;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
Queue* q;
int n, m;
void BFS(int** map, int** visited, int fy, int fx);

int main() {
	scanf("%d %d", &n, &m);
	int** map = (int**)calloc(n, sizeof(int*));
	int** visited = (int**)calloc(n, sizeof(int*));

	int i, j;
	for (i = 0; i < n; i++) {
		map[i] = (int*)calloc(m, sizeof(int));
		visited[i] = (int*)calloc(m, sizeof(int));
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (map[i][j] == 2) {
				BFS(map, visited, i, j);
				visited[i][j] = 0;
			}

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (map[i][j] == 1 && !visited[i][j])
				visited[i][j] = -1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", visited[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++) {
		free(map[i]);
		free(visited[i]);
	}
	free(map);
	return 0;
}

void BFS(int** map, int** visited, int fy, int fx) {
	q = (Queue*)calloc(n * m, sizeof(Queue));
	int front = -1, rear = 0;
	q[rear].y = fy;
	q[rear].x = fx;
	while (front < rear) {
		front++;
		int order = visited[q[front].y][q[front].x];
		for (int dir = 0; dir < 4; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (!visited[ny][nx] && map[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = order + 1;
				}
			}
		}
	}
}