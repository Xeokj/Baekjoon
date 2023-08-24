#include <bits/stdc++.h>
using namespace std;
int board[200][200];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> st[1001];
queue<pair<pair<int, int>, int>> q;
int N, K, S, X, Y;
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> K;
	for(i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j])
				st[board[i][j]].push_back({ i,j });
		}
	cin >> S >> X >> Y;
	X--;
	Y--;
	for (i = 1; i <= K; i++) {
		for (j = 0; j < st[i].size(); j++) {
			int y = st[i][j].first;
			int x = st[i][j].second;
			q.push({ {y,x},0 });
		}
	}
	BFS();
	cout << board[X][Y];
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int sec = q.front().second;
		if (sec == S || (y == X && x == Y))
			break;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (board[ny][nx])
				continue;
			board[ny][nx] = board[y][x];
			q.push({ {ny,nx},sec + 1 });
		}
	}
}