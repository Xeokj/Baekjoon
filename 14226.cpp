#include <bits/stdc++.h>
using namespace std;
bool visited[2001][1001];
int s;
queue<pair<pair<int, int>, int>> q;
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	BFS();
}

void BFS() {
	q.push({ {1,1},1 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int cnt = q.front().first.second;
		int clipboard = q.front().second;
		q.pop();
		if (x == s) {
			cout << cnt;
			return;
		}
		if (x < 1 || x >= s * 2)
			continue;
		if (visited[x][clipboard])
			continue;
		visited[x][clipboard] = 1;
		q.push({ {x,cnt + 1},x });	// 복사
		q.push({ {x + clipboard,cnt + 1},clipboard });	// 붙여넣기
		q.push({ {x - 1,cnt + 1},clipboard });	// 1개 삭제
	}
}