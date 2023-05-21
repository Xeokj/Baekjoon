#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 26

int map[MAX][MAX];
int visited[MAX][MAX];
int num[400];
int size;

void DFS(int i, int j, int N);

int compare(int* a, int* b) {
	return *a - *b;
}

int main() {
	int N, i, j, cnt = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				DFS(i, j, N);
				num[cnt] = size;
				cnt++;
				size = 0;
			}
		}
	}
	qsort(num, cnt, sizeof(int), compare);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d\n", num[i]);
	return 0;
}

void DFS(int i, int j, int N) {
	visited[i][j] = 1;
	size++;
	if (i - 1 >= 0)
		if(map[i - 1][j] && !visited[i - 1][j])
			DFS(i - 1, j, N);
	
	if (j - 1 >= 0)
		if(map[i][j - 1] && !visited[i][j - 1])
			DFS(i, j - 1, N);
	if (map[i + 1][j] && !visited[i + 1][j])
		DFS(i + 1, j, N);
	if (map[i][j + 1] && !visited[i][j + 1])
		DFS(i, j + 1, N);
}