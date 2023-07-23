#include <bits/stdc++.h>
using namespace std;

int ch[7];
int button[10];
int N, M, w, Min;
void backtr(int cur, int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, i, j;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> x;
		button[x] = 1;
	}

	Min = abs(N - 100);	// 100���� + �Ǵ� -�θ� N�� ����� ���

	if (M != 10) {
		// �ڸ��� Ȯ��
		int tmp = N;
		while (tmp) {
			tmp /= 10;
			w++;
		}
		if (N == 0)
			w = 1;
		// �� �ڸ� �� ���ڸ� �迭�� ����
		tmp = N;
		for (i = w - 1; i >= 0; i--) {
			ch[i] = tmp % 10;
			tmp /= 10;
		}
		backtr(0, 0);

		// �� �ڸ� ���� ������ ���� �� �ִ� �ִ��� ������ N�� ����� ���
		if (w >= 2) {
			for (i = 9; i >= 0; i--) {
				if (!button[i])
					break;
			}
			tmp = i;
			for (j = 2; j < w; j++) {
				tmp *= 10;
				tmp += i;
			}
			Min = min(Min, abs(tmp - N) + w - 1);
		}
		// �� �ڸ� �� ū ������ ���� �� �ִ� �ּ��� ������ N�� ����� ���
		if (w < 6) {
			for (i = 0; i < 10; i++) {
				if (!button[i])
					break;
			}
			if (i == 0) {
				for (j = 1; j < 10; j++) {
					if (!button[j])
						break;
				}
				if (j != 10) {
					tmp = j;
					for (int k = 0; k < w; k++)
						tmp *= 10;
					Min = min(Min, abs(tmp - N) + w + 1);
				}
			}
			else {
				tmp = i;
				for (j = 0; j < w; j++) {
					tmp *= 10;
					tmp += i;
				}
				Min = min(Min, abs(tmp - N) + w + 1);
			}
		}
	}
	cout << Min;
}

void backtr(int cur, int num) {
	if (cur == w) {
		int temp = abs(num - N) + w;	// ���� ��ư ������ �ͱ��� ����
		Min = min(Min, temp);
		return;
	}
	int i, stand = ch[cur];	// �ش� �ڸ��� ����
	// �ش� �ڸ��� ���� ��ư�� �������� ���
	if (!button[stand])
		backtr(cur + 1, num * 10 + stand);
	for (i = stand - 1; i >= 0; i--) {
		if (!button[i]) {
			backtr(cur + 1, num * 10 + i);
			break;
		}
	}
	for (i = stand + 1; i < 10; i++) {
		if (!button[i]) {
			backtr(cur + 1, num * 10 + i);
			break;
		}
	}
	for (i = 0; i < stand; i++) {
		if (!button[i]) {
			backtr(cur + 1, num * 10 + i);
			break;
		}
	}
	for (i = 9; i > stand; i--) {
		if (!button[i]) {
			backtr(cur + 1, num * 10 + i);
			break;
		}
	}
}