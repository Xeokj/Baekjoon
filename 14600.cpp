#include <bits/stdc++.h>
using namespace std;

int ans[4][4] = { {4,4,5,5},{4,3,3,5},{1,3,3,2},{1,1,2,2} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x, y, i, j;
	cin >> n >> x >> y;
	if (n == 1) {
		ans[2 - y][x - 1] = -1;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				if (ans[i][j] == -1) cout << "-1 ";
				else cout << "1 ";
			}
			cout << "\n";
		}
	}
	else {
		int tmp = ans[4 - y][x - 1];
		if (x == 1 || y == 1 || x == 4 || y == 4) {
			if (x == 1 && y > 1 && y < 4)
				ans[4 - y][x] = tmp;
			else if (x == 4 && y > 1 && y < 4)
				ans[4 - y][x - 2] = tmp;
			else if (y == 1 && x > 1 && x < 4)
				ans[3 - y][x - 1] = tmp;
			else if (y == 4 && x > 1 && x < 4)
				ans[5 - y][x - 1] = tmp;
			else {
				int dy[4] = { 1,1,-1,-1 };
				int dx[4] = { -1,1,1,-1 };
				for (int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny > 1 && ny < 4 && nx>1 && nx < 4)
						ans[4 - ny][nx - 1] = tmp;
				}
			}
		}
		ans[4 - y][x - 1] = -1;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				cout << ans[i][j] << ' ';
			cout << "\n";
		}
	}
}