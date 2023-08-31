#include <bits/stdc++.h>
using namespace std;
char board[50][50];
int dist[10], ranking[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int R, C, i, j;
	cin >> R >> C;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				dist[board[i][j] - '0'] = j;
			}
		}
	int cnt = 1;
	for (j = 48; j > 0; j--) {
		bool flg = 0;
		for (i = 1; i < 10; i++) {
			if (dist[i] == j) {
				flg = 1;
				ranking[i] = cnt;
			}
		}
		if (flg)
			cnt++;
	}
	for (i = 1; i < 10; i++)
		cout << ranking[i] << "\n";
}