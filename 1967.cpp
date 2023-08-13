#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<pair<int, int>> g[10001];
bool visited[10001];
void DFS(int v, int sum);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b, c, i;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	// 간선의 합이 가장 크려면 리프 노드들끼리 연결되어야 함
	for (i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			// 리프 노드는 연결된 노드가 1개 뿐이므로
			DFS(i, 0);
		}
	}
	cout << ans;
}

void DFS(int v, int sum) {
	visited[v] = 1;
	if (sum > ans)
		ans = sum;
	int size = g[v].size();
	for (int i = 0; i < size; i++) {
		int nv = g[v][i].first;
		int w = g[v][i].second;
		if (!visited[nv])
			DFS(nv, sum + w);
	}
	visited[v] = 0;
}