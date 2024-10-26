#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 9205번: 맥주 마시면서 걸어가기 (골드 5)
// DFS로 풀면 시간초과 남

bool visited[100];
int t, n;
int dfs(int x, int y, int enx, int eny, vector<pair<int, int>> loc);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int stx, sty, enx, eny;
		vector<pair<int, int>> loc;
		memset(visited, 0, sizeof(visited));

		cin >> stx >> sty;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			loc.push_back({ x,y });
		}
		cin >> enx >> eny;

		if (dfs(stx, sty, enx, eny, loc))
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}

int dfs(int x, int y, int enx, int eny, vector<pair<int,int>> loc) {
	if (abs(x - enx) + abs(y - eny) <= 1000)
		return 1;	// 현재 위치에서 목적지까지의 거리가 1000 이하일 때
	
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;	// 방문한 곳일 때
		if (abs(x - loc[i].first) + abs(y - loc[i].second) > 1000)
			continue;	// 거리가 1000을 넘을 때
		visited[i] = 1;
		if (dfs(loc[i].first, loc[i].second, enx, eny, loc))
			return 1;	// 목적지에 도달할 때
		visited[i] = 0;	// 목적지에 도달하지 못했을 때
	}
	return 0;	// 목적지에 도달하지 못했을 때
}