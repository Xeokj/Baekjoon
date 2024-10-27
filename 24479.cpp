#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 24479번: 알고리즘 수업 - 깊이 우선 탐색 1 (실버 2)
int visited[100001];
int n, m, r, order;
vector<int> graph[100001];
void dfs(int u);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << "\n";
	}
	return 0;
}

void dfs(int u) {
	order++;
	visited[u] = order;
	for (int i = 0; i < graph[u].size(); i++) {
		if (visited[graph[u][i]])
			continue;
		dfs(graph[u][i]);
	}
}