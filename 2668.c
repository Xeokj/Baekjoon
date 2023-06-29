#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int graph[101];
int visited[101];

void find(int start);

int main() {
	int N, i, cnt = 0;
	int ans[100];

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &graph[i]);
	
	for (i = 1; i <= N; i++) {
		if (!visited[i]) {
			find(i);
		}
	}

	for (i = 1; i <= N; i++) {
		if (visited[i]) {
			ans[cnt] = i;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d\n", ans[i]);
	return 0;
}

void find(int start) {
	int num = start;
	// ����Ŭ Ž��
	while (!visited[num]) {
		visited[num] = 1;
		num = graph[num];
	}
	// ����Ŭ �������� ��� visited���� ����
	while (start != num) {
		visited[start] = 0;
		start = graph[start];
	}
}