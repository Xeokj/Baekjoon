#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[9];
int used[9];
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);
	return 0;
}

int backtracking(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (used[i] == 0) {
			arr[num] = i;
			used[i] = 1;
			backtracking(num + 1);
			used[i] = 0;
		}
	}
}