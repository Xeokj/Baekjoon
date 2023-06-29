#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct _Pipe {
	int horiz;	// ����
	int diag;	// �밢��
	int verti;	// ����
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
		// 1���� ���ηθ� ������ �� �����Ƿ� ���� �κ��� 1�� �ʱ�ȭ
		if (map[0][j])	// ���� ������ �� �ں��ʹ� �� ���Ƿ�
			break;
		cases[0][j].horiz = 1;
	}

	for (i = 1; i < N; i++) {
		for (j = 2; j < N; j++) {
			// �����̷��� ���� ���� �ƴ� ����
			if (!map[i][j]) {
				cases[i][j].horiz = cases[i][j - 1].horiz + cases[i][j - 1].diag;
				cases[i][j].verti = cases[i - 1][j].diag + cases[i - 1][j].verti;
				// �밢������ �����̷��� �Ʒ�, �����ʱ��� ���� ����� �ϹǷ�
				if (!map[i][j - 1] && !map[i - 1][j - 1] && !map[i - 1][j])
					cases[i][j].diag = cases[i - 1][j - 1].horiz + cases[i - 1][j - 1].diag + cases[i - 1][j - 1].verti;
			}
		}
	}
	int sum = cases[N - 1][N - 1].horiz + cases[N - 1][N - 1].diag + cases[N - 1][N - 1].verti;
	printf("%d", sum);
	return 0;
}