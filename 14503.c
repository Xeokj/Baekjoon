#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define UNCLEANED 0
#define WALL 1
#define CLEANED 2

int clean(int** room, int y, int x, int* dir, int* cnt);
int find_dir(int** room, int y, int x, int* dir);

int main() {
	int N, M;
	int i, j;
	scanf("%d %d", &N, &M);

	/* 2차원 배열 동적 할당 */
	int** room = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		room[i] = (int*)malloc(sizeof(int) * M);

	/* y, x: 청소기의 좌표 (y행 x열), dir: 방향, cnt: 청소한 칸의 개수 */
	int y, x, dir, cnt = 0;
	scanf("%d %d %d", &y, &x, &dir);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			scanf("%d", &room[i][j]);
	}

	clean(room, y, x, &dir, &cnt);

	printf("%d", cnt);

	/* 동적 할당 해제 */
	for (i = 0; i < N; i++)
		free(room[i]);
	free(room);
	return 0;
}

int clean(int** room, int y, int x, int* dir, int* cnt) {
	if (room[y][x] == UNCLEANED) {	// 청소가 안 되어 있을 때
		room[y][x] = CLEANED;
		(*cnt)++;
	}
	/* 동서남북 모두 0이 아닐 때 */
	if (room[y - 1][x] && room[y][x + 1] && room[y + 1][x] && room[y][x - 1]) {

		if (room[y + 1][x] == CLEANED && *dir == 0)	// 북쪽을 바라보며 뒤로 갈 수 있을 때
			clean(room, y + 1, x, dir, cnt);
		else if (room[y][x - 1] == CLEANED && *dir == 1)	// 동쪽을 바라보며 뒤로 갈 수 있을 때
			clean(room, y, x - 1, dir, cnt);
		else if (room[y - 1][x] == CLEANED && *dir == 2)	// 남쪽을 바라보며 뒤로 갈 수 있을 때
			clean(room, y - 1, x, dir, cnt);
		else if (room[y][x + 1] == CLEANED && *dir == 3)	// 서쪽을 바라보며 뒤로 갈 수 있을 때
			clean(room, y, x + 1, dir, cnt);
		else
			return 0;
	}
	/* 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 */
	else {
		find_dir(room, y, x, dir);	// 반시계 방향으로 90도 회전하면서 청소할 방향을 찾음
		
		if(*dir == 0)
			clean(room, y - 1, x, dir, cnt);	// 북
		else if(*dir == 1)
			clean(room, y, x + 1, dir, cnt);	// 동
		else if(*dir == 2)
			clean(room, y + 1, x, dir, cnt);	// 남
		else if(*dir == 3)
			clean(room, y, x - 1, dir, cnt);	// 서
	}
}

/* 반시계 방향으로 회전하면서 청소할 방향을 찾는 함수 */
int find_dir(int** room, int y, int x, int* dir) {
	*dir = *dir - 1;	// 반시계 방향으로 90도 회전
	if (*dir == -1)
		*dir = 3;

	if (*dir == 0) {
		if (room[y - 1][x] == UNCLEANED)	// 북쪽이 청소되지 않은 경우
			return 0;	// 갈 수 있는 방향 찾기 성공
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 1) {
		if (room[y][x + 1] == UNCLEANED)	// 동쪽이 청소되지 않은 경우
			return 0;	// 갈 수 있는 방향 찾기 성공
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 2) {
		if (room[y + 1][x] == UNCLEANED)	// 남쪽이 청소되지 않은 경우
			return 0;	// 갈 수 있는 방향 찾기 성공
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 3) {
		if (room[y][x - 1] == UNCLEANED)	// 서쪽이 청소되지 않은 경우
			return 0;	// 갈 수 있는 방향 찾기 성공
		else
			find_dir(room, y, x, dir);
	}
	return 0;
}