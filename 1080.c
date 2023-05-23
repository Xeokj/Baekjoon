#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	
	int** matrix = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
		matrix[i] = (int*)calloc(M, sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &matrix[i][j]);
	
	int num, cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &num);
			if (num == matrix[i][j])
				matrix[i][j] = 0;
			else
				matrix[i][j] = 1;
		}
	}

	if (N < 3 || M < 3) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (matrix[i][j] == 1) {
					printf("-1");
					return 0;
				}
			}
		}
		printf("0");
		return 0;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (matrix[i][j] == 1) {
				if (i > N - 3 || j > M - 3) {
					printf("-1");
					return 0;
				}
				else {
					for (int x = i; x < i + 3; x++)
						for (int y = j; y < j + 3; y++)
							matrix[x][y] = !matrix[x][y];
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	for (i = 0; i < N; i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}