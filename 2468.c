#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX_H 101

typedef struct _Queue {
	int y;
	int x;
} Queue;

Queue q[10000];
int front, rear, N;

int map[100][100];
int visited[100][100];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int arr_h[MAX_H];	// 높이 저장
void BFS(int height, int y, int x);

int main() {
	int ans = 1, cnt, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			arr_h[map[i][j]]++;
		}
	}

	for (int height = 1; height < MAX_H; height++) {
		if (arr_h[height] != 0) {
			cnt = 0;
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (map[i][j] > height && !visited[i][j]) {
						BFS(height, i, j);
						cnt++;
					}
				}
			}
			if (cnt > ans)
				ans = cnt;
			for (i = 0; i < N; i++)
				memset(visited[i], 0, sizeof(int) * N);
		}
	}
	printf("%d", ans);
	return 0;
}

void BFS(int height, int y, int x) {
	front = -1;
	rear = -1;

	rear++;
	q[rear].y = y;
	q[rear].x = x;
	visited[y][x] = 1;
	while (front < rear) {
		front++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (map[ny][nx] > height && !visited[ny][nx]) {
				rear++;
				q[rear].y = ny;
				q[rear].x = nx;
				visited[ny][nx] = 1;
			}
		}
	}
}