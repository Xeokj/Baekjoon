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

	Min = abs(N - 100);	// 100에서 + 또는 -로만 N을 만드는 경우

	if (M != 10) {
		// 자릿수 확인
		int tmp = N;
		while (tmp) {
			tmp /= 10;
			w++;
		}
		if (N == 0)
			w = 1;
		// 각 자리 별 숫자를 배열에 저장
		tmp = N;
		for (i = w - 1; i >= 0; i--) {
			ch[i] = tmp % 10;
			tmp /= 10;
		}
		backtr(0, 0);

		// 한 자리 작은 수에서 만들어낼 수 있는 최대의 수에서 N을 만드는 경우
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
		// 한 자리 더 큰 수에서 만들어낼 수 있는 최소의 수에서 N을 만드는 경우
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
		int temp = abs(num - N) + w;	// 숫자 버튼 누르는 것까지 더함
		Min = min(Min, temp);
		return;
	}
	int i, stand = ch[cur];	// 해당 자리의 숫자
	// 해당 자리의 숫자 버튼이 눌러지는 경우
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