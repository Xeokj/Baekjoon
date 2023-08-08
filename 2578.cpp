#include <bits/stdc++.h>
using namespace std;
int bingo[5][5];
typedef struct _LOC {
	int y;
	int x;
} LOC;
LOC loc[26];
int Find();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N = 25, num, i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++) {
			cin >> bingo[i][j];
			loc[bingo[i][j]].y = i;
			loc[bingo[i][j]].x = j;
		}
	int ny, nx, flg = 0, ans = 0;
	while (N--) {
		cin >> num;
		if (!flg) {
			ny = loc[num].y;
			nx = loc[num].x;
			bingo[ny][nx] = 0;
			if (N <= 15) {
				if (Find() >= 3) {
					ans = 25 - N;
					flg = 1;
				}
			}
		}
	}
	cout << ans;
}

int Find() {
	int i, j, line = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (bingo[i][j])
				break;
		}
		if (j == 5)
			line++;
	}
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (bingo[i][j])
				break;
		}
		if (i == 5)
			line++;
	}
	for (i = 0; i < 5; i++)
		if (bingo[i][i])
			break;
	if (i == 5)
		line++;
	for (i = 0; i < 5; i++)
		if (bingo[4 - i][i])
			break;
	if (i == 5)
		line++;
	return line;
}