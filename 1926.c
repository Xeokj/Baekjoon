#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int N, M, i, j, cnt;

void DFS(int** map, int** visited, int y, int x);

int main() {
	scanf("%d %d", &N, &M);
	int** map = (int**)calloc(N, sizeof(int*));
	int** visited = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
		map[i] = (int*)calloc(M, sizeof(int));
	for (i = 0; i < N; i++)
		visited[i] = (int*)calloc(M, sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int max = 0, print = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				print++;
				cnt = 0;
				DFS(map, visited, i, j);
				if (cnt > max)
					max = cnt;
			}
		}
	}
	printf("%d\n%d\n", print, max);

	for (i = 0; i < N; i++)
		free(map[i]);
	for (i = 0; i < N; i++)
		free(visited[i]);
	free(map);
	free(visited);
	return 0;
}

void DFS(int** map, int** visited, int y, int x) {
	visited[y][x] = 1;
	cnt++;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		else if (map[ny][nx] && !visited[ny][nx])
				DFS(map, visited, ny, nx);
	}
}