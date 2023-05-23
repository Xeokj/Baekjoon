#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

int arr[MAX][MAX];
int visited[MAX];
int cnt = 0;

void DFS(int x, int N);

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	int a, b;
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	DFS(1, N);
	printf("%d", cnt);
	return 0;
}

void DFS(int x, int N) {
	visited[x] = 1;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[x][i]) {
			cnt++;
			DFS(i, N);
		}
	}
}