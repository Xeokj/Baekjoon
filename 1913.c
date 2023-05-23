#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, num, i, j;
	scanf("%d %d", &N, &num);

	int** arr = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
		arr[i] = (int*)calloc(N, sizeof(int));

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	int r = N / 2;	// 반지름
	int x = N / 2, y = N / 2;
	int cnt = 1;
	arr[x][y] = cnt;	// 시작점에 1을 부여

	for (int level = 1; level <= r; level++) {
		x--;	// 한 칸 위로 올려서 시작
		for (i = 0; i < 4; i++) {
			for (j = 1; j <= level * 2; j++) {
				if (i == 0 && j == 1) {
					arr[x][y] = ++cnt;
					continue;
				}				
				x += dx[i];
				y += dy[i];
				arr[x][y] = ++cnt;
			}
		}
	}

	int num_x, num_y;	// 찾을 숫자의 좌표
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
			if (arr[i][j] == num) {
				num_x = i;
				num_y = j;
			}
		}
		printf("\n");
	}
	printf("%d %d", num_x + 1, num_y + 1);

	for (i = 0; i < N; i++)
		free(arr[i]);
	free(arr);
	return 0;
}