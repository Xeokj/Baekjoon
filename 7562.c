#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 300

typedef struct _Queue {
	int y;
	int x;
} Queue;

Queue q[MAX * MAX + 1];
int visited[MAX][MAX];
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int front, rear;

void BFS(int py, int px, int desy, int desx, int I);

int main() {
	int T, I, i;
	int py, px, desy, desx;
	scanf("%d", &T);
	while (T) {
		scanf("%d", &I);
		scanf("%d %d", &py, &px);
		scanf("%d %d", &desy, &desx);

		BFS(py, px, desy, desx, I);
		printf("%d\n", visited[desy][desx]);

		for (i = 0; i < I; i++)
			memset(visited[i], 0, sizeof(int) * I);
		T--;
	}
	return 0;
}

void BFS(int py, int px, int desy, int desx, int I) {
	front = 0; rear = 0;
	q[rear].y = py;
	q[rear].x = px;
	visited[py][px] = 0;
	while (q[front].y != desy || q[front].x != desx) {
		int order = visited[q[front].y][q[front].x];
		for (int dir = 0; dir < 8; dir++) {
			int ny = q[front].y + dy[dir];
			int nx = q[front].x + dx[dir];
			if (ny >= 0 && ny < I && nx >= 0 && nx < I) {
				if (!visited[ny][nx]) {
					rear++;
					q[rear].y = ny;
					q[rear].x = nx;
					visited[ny][nx] = order + 1;
				}
			}
		}
		front++;
	}
}