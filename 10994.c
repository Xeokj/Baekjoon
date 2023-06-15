#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char arr[400][400];
int max_len;
void star(int N, int y, int x);

int main() {
	int N, i, j;
	scanf("%d", &N);
	max_len = 4 * N - 3;

	for (i = 0; i < max_len; i++) {
		for (j = 0; j < max_len; j++)
			arr[i][j] = ' ';
	}

	star(N, 0, 0);

	for (i = 0; i < max_len; i++) {
		for (j = 0; j < max_len; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}

void star(int N , int y, int x) {
	int i, len = 4 * N - 3;
	for (i = 0; i < len; i++) {
		arr[y][x + i] = '*';	// 1번
		arr[y + i][x] = '*';	// 2번
		arr[max_len - 1 - y][x + i] = '*';	// 3번
		arr[y + i][max_len - 1 - x] = '*';	// 4번
	}
	if (N > 1)
		star(N - 1, y + 2, x + 2);
}