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
	/* �ٸ� ���� ���ͼ� 9��� �ϰ� �Ǹ� diff = 1�� �� */
	for (i = x; i < x + N; i++) {
		for (j = y; j < y + N; j++) {
			/* �ٸ� ���� ������ ��� */
			/* �� �� 9��� �ϰ��� �� ũ�⿡�� �� �̻� Ȯ���� �ʿ� �����Ƿ� */
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