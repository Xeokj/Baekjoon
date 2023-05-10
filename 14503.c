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

	/* 2���� �迭 ���� �Ҵ� */
	int** room = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		room[i] = (int*)malloc(sizeof(int) * M);

	/* y, x: û�ұ��� ��ǥ (y�� x��), dir: ����, cnt: û���� ĭ�� ���� */
	int y, x, dir, cnt = 0;
	scanf("%d %d %d", &y, &x, &dir);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			scanf("%d", &room[i][j]);
	}

	clean(room, y, x, &dir, &cnt);

	printf("%d", cnt);

	/* ���� �Ҵ� ���� */
	for (i = 0; i < N; i++)
		free(room[i]);
	free(room);
	return 0;
}

int clean(int** room, int y, int x, int* dir, int* cnt) {
	if (room[y][x] == UNCLEANED) {	// û�Ұ� �� �Ǿ� ���� ��
		room[y][x] = CLEANED;
		(*cnt)++;
	}
	/* �������� ��� 0�� �ƴ� �� */
	if (room[y - 1][x] && room[y][x + 1] && room[y + 1][x] && room[y][x - 1]) {

		if (room[y + 1][x] == CLEANED && *dir == 0)	// ������ �ٶ󺸸� �ڷ� �� �� ���� ��
			clean(room, y + 1, x, dir, cnt);
		else if (room[y][x - 1] == CLEANED && *dir == 1)	// ������ �ٶ󺸸� �ڷ� �� �� ���� ��
			clean(room, y, x - 1, dir, cnt);
		else if (room[y - 1][x] == CLEANED && *dir == 2)	// ������ �ٶ󺸸� �ڷ� �� �� ���� ��
			clean(room, y - 1, x, dir, cnt);
		else if (room[y][x + 1] == CLEANED && *dir == 3)	// ������ �ٶ󺸸� �ڷ� �� �� ���� ��
			clean(room, y, x + 1, dir, cnt);
		else
			return 0;
	}
	/* ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ��� */
	else {
		find_dir(room, y, x, dir);	// �ݽð� �������� 90�� ȸ���ϸ鼭 û���� ������ ã��
		
		if(*dir == 0)
			clean(room, y - 1, x, dir, cnt);	// ��
		else if(*dir == 1)
			clean(room, y, x + 1, dir, cnt);	// ��
		else if(*dir == 2)
			clean(room, y + 1, x, dir, cnt);	// ��
		else if(*dir == 3)
			clean(room, y, x - 1, dir, cnt);	// ��
	}
}

/* �ݽð� �������� ȸ���ϸ鼭 û���� ������ ã�� �Լ� */
int find_dir(int** room, int y, int x, int* dir) {
	*dir = *dir - 1;	// �ݽð� �������� 90�� ȸ��
	if (*dir == -1)
		*dir = 3;

	if (*dir == 0) {
		if (room[y - 1][x] == UNCLEANED)	// ������ û�ҵ��� ���� ���
			return 0;	// �� �� �ִ� ���� ã�� ����
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 1) {
		if (room[y][x + 1] == UNCLEANED)	// ������ û�ҵ��� ���� ���
			return 0;	// �� �� �ִ� ���� ã�� ����
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 2) {
		if (room[y + 1][x] == UNCLEANED)	// ������ û�ҵ��� ���� ���
			return 0;	// �� �� �ִ� ���� ã�� ����
		else
			find_dir(room, y, x, dir);
	}
	else if (*dir == 3) {
		if (room[y][x - 1] == UNCLEANED)	// ������ û�ҵ��� ���� ���
			return 0;	// �� �� �ִ� ���� ã�� ����
		else
			find_dir(room, y, x, dir);
	}
	return 0;
}