#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct _Pipe {
	int horiz;	// 가로
	int diag;	// 대각선
	int verti;	// 세로
} pipe;

pipe cases[16][16];
int map[16][16];

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	for (j = 0; j < N; j++) {
		// 1행은 가로로만 움직일 수 있으므로 가로 부분을 1로 초기화
		if (map[0][j])	// 벽이 있으면 그 뒤부터는 못 가므로
			break;
		cases[0][j].horiz = 1;
	}

	for (i = 1; i < N; i++) {
		for (j = 2; j < N; j++) {
			// 움직이려는 곳이 벽이 아닐 때만
			if (!map[i][j]) {
				cases[i][j].horiz = cases[i][j - 1].horiz + cases[i][j - 1].diag;
				cases[i][j].verti = cases[i - 1][j].diag + cases[i - 1][j].verti;
				// 대각선으로 움직이려면 아래, 오른쪽까지 벽이 없어야 하므로
				if (!map[i][j - 1] && !map[i - 1][j - 1] && !map[i - 1][j])
					cases[i][j].diag = cases[i - 1][j - 1].horiz + cases[i - 1][j - 1].diag + cases[i - 1][j - 1].verti;
			}
		}
	}
	int sum = cases[N - 1][N - 1].horiz + cases[N - 1][N - 1].diag + cases[N - 1][N - 1].verti;
	printf("%d", sum);
	return 0;
}