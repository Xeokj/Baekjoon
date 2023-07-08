#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
	int light;	// �� ������ ������ ����
	int heavy;	// �� ���ſ� ������ ����
} weight;

int graph[MAX][MAX];	// ���� �׷���
int visited[MAX];
weight w[MAX];
int N, M, cnt;

void DFS(int num);

int main() {
	scanf("%d %d", &N, &M);
	int a, b, i, j;
	while (M) {
		// a: �� ���ſ� ��, b: �� ������ ��
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		M--;
	}

	for (i = 1; i <= N; i++) {
		cnt = 0;
		for (j = 1; j <= N; j++) {
			if (graph[i][j] && !visited[j]) {
				// j�� �������� ���ſ� ������ �ϳ� �� �ִ� ���̹Ƿ�
				(w[j].heavy)++;
				cnt++;	// i�� �������� �� ������ ����(j�� ����)�� ���� �ϳ� �߰�
				visited[j] = 1;	// �ߺ� ����
				DFS(j);
			}
		}
		w[i].light = cnt;
		// visited �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
	}

	int ans = 0;
	// �� ���ſ� �����̳� �� ������ ������ ������ N/2������ ũ�� �߰��� �� �� ����
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