#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct _Queue {
	int y;
	int x;
} Queue;

Queue q[2500];
int N, M;
int map[50][50];
int visited[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int BFS(int i, int j);

int main() {
	scanf("%d %d", &N, &M);
	int i, j;
	char tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf(" %c", &tmp);
			if (tmp == 'L')
				map[i][j] = 1;
		}
	}
	int time, max = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j]) {
				time = BFS(i, j);
				if (time > max)
					max = time;
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	printf("%d", max);
	return 0;
}

int BFS(int i, int j) {
	int front = -1, rear = 0;
	q[rear].y = i;
	q[rear].x = j;
	visited[i][j] = 1;
	while (front < rear) {
		front++;
		int org_y = q[front].y;
		int org_x = q[front].x;
		for (int dir = 0; dir < 4; dir++) {
			int ny = org_y + dy[dir];
			int nx = org_x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (map[ny][nx] && !visited[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = visited[org_y][org_x] + 1;
				}
			}
		}
	}
	return visited[q[rear].y][q[rear].x] - 1;
}