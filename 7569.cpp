#include <bits/stdc++.h>
using namespace std;

int box[100][100][100];
typedef pair<int, pair<int, int>> cor;
queue<cor> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, H, i, j, k;
	cin >> M >> N >> H;
	for (i = 0; i < H; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push(make_pair(i, make_pair(j, k)));
			}

	int dx[6] = { 1,0,-1,0,0,0 };
	int dy[6] = { 0,1,0,-1,0,0 };
	int dz[6] = { 0,0,0,0,1,-1 };

	while (!q.empty()) {
		cor qfront = q.front();
		q.pop();
		int curz = qfront.first;
		int cury = qfront.second.first;
		int curx = qfront.second.second;
		int order = box[curz][cury][curx];
		for (int dir = 0; dir < 6; dir++) {
			int nz = curz + dz[dir];
			int ny = cury + dy[dir];
			int nx = curx + dx[dir];
			if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (!box[nz][ny][nx]) {
					q.push(make_pair(nz, make_pair(ny, nx)));
					box[nz][ny][nx] = order + 1;
				}
			}
		}
	}
	int max = 0;
	for (i = 0; i < H; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++) {
				if (box[i][j][k]) {
					if (box[i][j][k] > max)
						max = box[i][j][k];
				}
				else {
					cout << "-1";
					return 0;
				}
			}
	cout << max - 1;
}