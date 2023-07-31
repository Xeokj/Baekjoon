#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char arr[1000][1000];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue<pair<pair<int, int>, int>> q;
// q에서 first는 F또는 J의 좌표, second는 J의 시간 (시간은 1부터 시작)
// 따라서 second가 0이면 F, 1 이상이면 J 
// J가 테두리에 다다르면 BFS를 종료함
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	int i, j, jy, jx;
	// 매 시간마다 불이 먼저 퍼진 후 지훈이가 움직여야 하므로
	// 입력을 받으며 F를 먼저 queue에 넣어줌
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				jy = i;
				jx = j;
			}
			else if (arr[i][j] == 'F')
				q.push(make_pair(make_pair(i, j), 0));
		}
	// J를 queue에 넣어주고, 시간은 1부터 시작
	q.push(make_pair(make_pair(jy, jx), 1));
	BFS();
	if (ans)
		cout << ans;
	else
		cout << "IMPOSSIBLE";
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if ((y == 0 || y == R - 1 || x == 0 || x == C - 1) && t) {
			ans = t;
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
				// t가 1이상이면 J, 0이면 F
				if (t) {
					if (arr[ny][nx] == '.') {
						// J의 이동경로를 저장하기 위해 J로 바꿔줌
						arr[ny][nx] = 'J';
						// 시간 1 증가해서 queue에 넣음
						q.push(make_pair(make_pair(ny, nx), t + 1));
					}
				}
				else {
					if (arr[ny][nx] == '.' || arr[ny][nx] == 'J') {
						// F가 이동할 위치를 F로 바꿔줌
						arr[ny][nx] = 'F';
						q.push(make_pair(make_pair(ny, nx), 0));
					}
				}
			}
		}
	}
}