#include <bits/stdc++.h>
#define INF 1500
using namespace std;
int n, m, r;
int items[101], dist[101];
vector<pair<int,int>> graph[101];
// Dijkstra

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, l, i, j;
	cin >> n >> m >> r;
	for (i = 1; i <= n; i++)
		cin >> items[i];
	for (i = 0; i < r; i++) {
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}

	int sum, ans = 0;
	for (i = 1; i <= n; i++) {
		fill(dist, dist + n + 1, INF);
		dist[i] = 0;
		priority_queue<pair<int, int>> pq;
		int v, cost;
		pq.push(make_pair(0, i));
		while (!pq.empty()) {
			cost = pq.top().first;
			v = pq.top().second;
			pq.pop();
			for (j = 0; j < graph[v].size(); j++) {
				int nv = graph[v][j].first;
				int ncost = cost + graph[v][j].second;
				if (ncost < dist[nv]) {
					dist[nv] = ncost;
					pq.push(make_pair(ncost, nv));
				}
			}
		}
		sum = 0;
		for (j = 1; j <= n; j++) {
			if (dist[j] <= m)
				sum += items[j];
		}
		if (sum > ans)
			ans = sum;
	}
	cout << ans;
}