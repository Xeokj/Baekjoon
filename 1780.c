#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2187

int arr[MAX][MAX];
int answer[3];
void find(int x, int y, int N);

int main() {
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	find(0, 0, N);
	printf("%d\n%d\n%d\n", answer[0], answer[1], answer[2]);
	return 0;
}

void find(int x, int y, int N) {
	int i, j, k, l;
	int base = arr[x][y];
	int diff = 0;
	/* 다른 수가 나와서 9등분 하게 되면 diff = 1이 됨 */
	for (i = x; i < x + N; i++) {
		for (j = y; j < y + N; j++) {
			/* 다른 수가 나오는 경우 */
			/* 한 번 9등분 하고나면 그 크기에서 더 이상 확인할 필요 없으므로 */
			if (arr[i][j] != base && diff == 0) {
				diff = 1;
				for (k = 0; k < 3; k++) {
					for (l = 0; l < 3; l++) {
						find(x + k * N / 3, y + l * N / 3, N / 3);
					}
				}
			}
		}
	}
	if (diff == 0)
		answer[arr[x][y] + 1]++;
}