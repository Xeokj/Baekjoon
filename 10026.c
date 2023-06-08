#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Queue {
	int y;
	int x;
} Queue;

int front = -1, rear = -1;
int N, cnt1, cnt2;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void eyes1(char** map, int** visited, int i, int j);
void eyes2(char** map, int** visited, int i, int j);

int main() {
	scanf("%d", &N);
	char** map = (char**)calloc(N, sizeof(char*));
	int** visited = (int**)calloc(N, sizeof(int*));

	int i, j;
	for (i = 0; i < N; i++) {
		map[i] = (char*)calloc(N + 2, sizeof(char));
		visited[i] = (int*)calloc(N, sizeof(int));
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited[i][j]) {
				eyes1(map, visited, i, j);
				cnt1++;
			}
		}
	}

	for (i = 0; i < N; i++) {
		memset(visited[i], 0, sizeof(int) * N);
	}

	front = -1;
	rear = -1;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited[i][j]) {
				eyes2(map, visited, i, j);
				cnt2++;
			}
		}
	}

	printf("%d %d", cnt1, cnt2);

	for (i = 0; i < N; i++) {
		free(map[i]);
		free(visited[i]);
	}
	free(map);
	free(visited);
	return 0;
}

void eyes1(char** map, int** visited, int i, int j) {
	char color = map[i][j];

	Queue* q = (Queue*)calloc((N + 1) * (N + 1), sizeof(Queue));
	rear++;
	q[rear].y = i;
	q[rear].x = j;
	visited[i][j] = 1;
	while (front < rear) {
		front++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (map[ny][nx] == color && !visited[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = 1;
				}
			}
		}
	}
	free(q);
}

void eyes2(char** map, int** visited, int i, int j) {
	char color = map[i][j];

	Queue* q = (Queue*)calloc((N + 1) * (N + 1), sizeof(Queue));
	rear++;
	q[rear].y = i;
	q[rear].x = j;
	visited[i][j] = 1;
	while (front < rear) {
		front++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx]) {
					if (color == 'R' || color == 'G') {
						if (map[ny][nx] != 'B') {
							rear++;
							q[rear].y = ny;
							q[rear].x = nx;
							visited[ny][nx] = 1;
						}
					}
					else if (map[ny][nx] == color) {
						rear++;
						q[rear].y = ny;
						q[rear].x = nx;
						visited[ny][nx] = 1;
					}

				}
			}
		}
	}
	free(q);
}