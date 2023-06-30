#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 1001

int coord[MAX][MAX];
int visited[MAX];
int N, M;
void DFS(int V);

int main() {
	int a, b, i;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		coord[a][b] = 1;
		coord[b][a] = 1;
	}

	int cnt = 0;
	for (i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}

void DFS(int V) {
	visited[V] = 1;
	for (int i = 1; i <= N; i++)
		if (coord[V][i] && !visited[i])
			DFS(i);
}