#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int arr[4][8];
int rotate[4];

int main() {
	int K, i, j, temp;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	scanf("%d", &K);
	int num, turn;
	while (K) {
		scanf("%d %d", &num, &turn);
		num--;
		rotate[num] = turn;
		int tmp_turn = turn;
		for (i = num - 1; i >= 0; i--) {
			tmp_turn *= -1;
			if (arr[i][2] != arr[i + 1][6])
				rotate[i] = tmp_turn;
			else
				break;
		}
		tmp_turn = turn;
		for (i = num + 1; i < 4; i++) {
			tmp_turn *= -1;
			if (arr[i][6] != arr[i - 1][2])
				rotate[i] = tmp_turn;
			else
				break;
		}
		for (i = 0; i < 4; i++) {
			// 시계 방향
			if (rotate[i] == 1) {
				temp = arr[i][7];
				for (j = 7; j > 0; j--)
					arr[i][j] = arr[i][j - 1];
				arr[i][0] = temp;
			}
			else if (rotate[i] == -1) {	// 반시계 방향
				temp = arr[i][0];
				for (j = 0; j < 7; j++)
					arr[i][j] = arr[i][j + 1];
				arr[i][7] = temp;
			}
		}
		memset(rotate, 0, sizeof(rotate));
		K--;
	}
	int ans = 0;
	if (arr[0][0])
		ans += 1;
	if (arr[1][0])
		ans += 2;
	if (arr[2][0])
		ans += 4;
	if (arr[3][0])
		ans += 8;
	printf("%d", ans);
	return 0;
}