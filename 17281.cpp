#include <bits/stdc++.h>
using namespace std;
int order[9], inning[9], field[4], input[50][10];
int permu[8] = { 2,3,4,5,6,7,8,9 };
/*
	- permu: next_permutaion �Լ� ������ �뵵 (���� ��ġ��)
	- order: index=0~2�� permu�� index=0~2�� ��ġ,
		index=4~8�� permu�� index=4~8�� ��ġ�ϰ�, index=3�� 1�� ������
		(index[i]���� Ÿ�ڴ� i+1��° ������ ����)
		Ex. order : 2 1 5 4 8 9 7 6 3
			2�� = ù ��° ����, 1�� = �� ��° ����, 5�� = �� ��° ����, ...
	- inning: Permutation �Լ��� ������ ��ġ�� ������ ���� ���� �̴��� ���
	- field: �� �翡 ����� �ִ��� 0�� 1�� ǥ��(Ex. field[1] = 1�� 1�翡 ����� ������ ����)
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, ans = 0, i, j, k;
	cin >> N;
	order[3] = 1;	// 4��° ������ ������ 1������ ����
	for (i = 0; i < N; i++)
		for (j = 1; j <= 9; j++)
			cin >> input[i][j];
	// next_permutation �Լ��� �̿��� ���� ����
	do {
		// index=3�� �����ϰ� order�� ���� ��ġ
		for (i = 0; i < 3; i++)
			order[i] = permu[i];
		for (i = 3; i < 8; i++)
			order[i + 1] = permu[i];

		int score = 0, zero, idx = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < 9; j++)
				inning[j] = input[i][order[j]];
			zero = 0;
			// 0�� 3���̸� ���� �̴����� �Ѿ�Ƿ�
			while (zero < 3) {
				if (inning[idx] == 1) {
					// ��Ÿ
					if (field[3]) {
						score++;
						field[3] = 0;	// 3�縦 �����
					}
					for (k = 2; k > 0; k--) {
						// 1��� 2��� �� ĭ�� �Ű���
						if (field[k]) {
							field[k] = 0;
							field[k + 1] = 1;
						}
					}
					field[1] = 1;	// 1�縦 ä����
				}
				else if (inning[idx] == 2) {
					// 2��Ÿ
					if (field[3]) {
						score++;
						field[3] = 0;	// 3�縦 �����
					}
					if (field[2]) {
						// 2������� Ȩ�� �����Ƿ� 2�絵 �����
						score++;
						field[2] = 0;
					}
					if (field[1]) {
						//	1�翡 �ִ� ������ 3��� �̵�
						field[1] = 0;
						field[3] = 1;
					}
					field[2] = 1;	// 2�縦 ä����
				}
				else if (inning[idx] == 3) {
					// 3��Ÿ
					for (k = 3; k > 0; k--) {
						/* 1����� 3����� ��� Ȩ���� ���� �� �����Ƿ�
						������ 1�� �ø��� �ش� �縦 ����� */
						if (field[k]) {
							score++;
							field[k] = 0;
						}
						field[3] = 1;	// 3�縦 ä����
					}
				}
				else if (inning[idx] == 4) {
					// Ȩ��
					for (k = 3; k > 0; k--) {
						// ��� �翡 �ִ� �����ŭ ������ �ø��� �ش� �縦 ���
						if (field[k]) {
							score++;
							field[k] = 0;
						}
					}
					score++;	// Ȩ��ģ ������ Ȩ���� ������ ����
				}
				else
					zero++;	// �ƿ��� ��
				idx = (idx + 1) % 9;	// idx�� 1�� ���������ְ� 8�� ������ �ٽ� 0���� ����
			}
			// �� �̴��� ������ field �ʱ�ȭ
			for (k = 1; k < 4; k++)
				field[k] = 0;
		}
		if (score > ans)
			ans = score;
	} while (next_permutation(permu, permu + 8));
	cout << ans;
}