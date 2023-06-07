#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int N, M;
int arr[8];
void NnM(int cnt);

int main() {
	scanf("%d %d", &N, &M);
	NnM(0);
	return 0;
}

void NnM(int cnt) {
	int i;
	if (cnt == M) {
		for (i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (i = 1; i <= N; i++) {
			arr[cnt] = i;
			NnM(cnt + 1);
		}
	}
}