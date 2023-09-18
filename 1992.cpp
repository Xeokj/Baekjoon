#include <bits/stdc++.h>
using namespace std;
// 백준 1992번: 쿼드트리 (실버 1)
char pic[64][64];
string ans;
void compress(int y, int x, int N);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> pic[i][j];
	compress(0, 0, N);
	cout << ans;
}

void compress(int y, int x, int N) {
	bool flg = 0;
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (pic[i][j] != pic[y][x]) {
				flg = 1;
				break;
			}
		}
		if (flg)
			break;
	}
	if (flg) {
		ans += '(';
		compress(y, x, N / 2);
		compress(y, x + N / 2, N / 2);
		compress(y + N / 2, x, N / 2);
		compress(y + N / 2, x + N / 2, N / 2);
		ans += ')';
	}
	else
		ans += pic[y][x];
}