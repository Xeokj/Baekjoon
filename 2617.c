#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
	int light;	// 더 가벼운 구슬의 개수
	int heavy;	// 더 무거운 구슬의 개수
} weight;

int graph[MAX][MAX];	// 방향 그래프
int visited[MAX];
weight w[MAX];
int N, M, cnt;

void DFS(int num);

int main() {
	scanf("%d %d", &N, &M);
	int a, b, i, j;
	while (M) {
		// a: 더 무거운 쪽, b: 더 가벼운 쪽
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		M--;
	}

	for (i = 1; i <= N; i++) {
		cnt = 0;
		for (j = 1; j <= N; j++) {
			if (graph[i][j] && !visited[j]) {
				// j번 구슬보다 무거운 구슬이 하나 더 있는 것이므로
				(w[j].heavy)++;
				cnt++;	// i번 구슬보다 더 가벼운 구슬(j번 구슬)의 개수 하나 추가
				visited[j] = 1;	// 중복 방지
				DFS(j);
			}
		}
		w[i].light = cnt;
		// visited 초기화
		memset(visited, 0, sizeof(visited));
	}

	int ans = 0;
	// 더 무거운 구슬이나 더 가벼운 구슬의 개수가 N/2개보다 크면 중간이 될 수 없음
	for (i = 1; i <= N; i++) {
		if (w[i].light > N / 2 || w[i].heavy > N / 2)
			ans++;
	}
	printf("%d", ans);
	return 0;
}

void DFS(int num) {
	for (int j = 1; j <= N; j++) {
		if (graph[num][j] && !visited[j]) {
			(w[j].heavy)++;
			cnt++;
			visited[j] = 1;
			DFS(j);
		}
	}
}