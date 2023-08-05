#include <bits/stdc++.h>
using namespace std;

int board[101];
int visited[101];
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, a, b, i;
	cin >> N >> M;
	for (i = 0; i < N + M; i++) {
		cin >> a >> b;
		board[a] = b;
	}
	// BFS
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		int order = visited[x];
		q.pop();
		for (i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx >= 100) {
				cout << order;
				return 0;
			}
			while (board[nx])
				nx = board[nx];
			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = order + 1;
			}
		}
	}
	return 0;
}