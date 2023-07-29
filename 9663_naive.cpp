#include <bits/stdc++.h>

using namespace std;
int arr[15][15];
int col[15];
int N, ans = 0;
void NQueen(int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	NQueen(0);
	cout << ans;
}

void NQueen(int y) {
	if (y == N) {
		ans++;
		return;
	}
	int i, x;
	for (i = 0; i < N; i++) {
		if (!col[i]) {
			int flag = 0;
			for (x = 1; x <= y; x++) {
				if (i - x >= 0) {
					if (arr[y - x][i - x]) {
						flag = 1;
						break;
					}
				}
				if (i + x < N) {
					if (arr[y - x][i + x]) {
						flag = 1;
						break;
					}
				}
			}
			if (!flag) {
				arr[y][i] = 1;
				col[i] = 1;
				NQueen(y + 1);
				arr[y][i] = 0;
				col[i] = 0;
			}
		}
	}
}