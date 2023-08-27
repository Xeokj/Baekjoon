#include <bits/stdc++.h>
using namespace std;
int N, stx, sty, enx, eny;
bool visited[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, x, y, i;
	cin >> t;
	while (t--) {
		cin >> N;
		cin >> stx >> sty;
		vector<pair<int, int>> node;
		node.push_back({ stx,sty });
		for (i = 0; i < N; i++) {
			cin >> x >> y;
			node.push_back({ x,y });
		}
		cin >> enx >> eny;
		node.push_back({ enx,eny });
		bool flg = 0;
		queue<pair<int, int>> q;
		q.push({ stx,sty });
		visited[0] = 1;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == enx && y == eny) {
				flg = 1;
				cout << "happy\n";
				break;
			}
			for (i = 1; i < N + 2; i++) {
				if (visited[i])
					continue;
				int nx = node[i].first;
				int ny = node[i].second;
				if (abs(nx - x) + abs(ny - y) > 1000)
					continue;
				q.push({ nx,ny });
				visited[i] = 1;
			}
		}
		if (!flg)
			cout << "sad\n";
		node.clear();
		memset(visited, 0, sizeof(visited));
	}
}