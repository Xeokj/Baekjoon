#include <bits/stdc++.h>
using namespace std;
#define INF (~0U>>2)
int N, M, X;
vector<int> dist;
int ans[1001];
vector<pair<int, int>> g[1001][2];
void dijkstra(int st);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> X;
	int a, b, c, i, max = 0;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		g[a][0].push_back({ c,b });	// 정방향
		g[b][1].push_back({ c,a });	// 역방향
	}
	dijkstra(1);	// 각 노드에서 X로 돌아오는 최단 거리
	dijkstra(0);	// X에서 각 노드로의 최단 거리
	for (i = 1; i <= N; i++) {
		if (ans[i] > max)
			max = ans[i];
	}
	cout << max;
}

void dijkstra(int k) {
	dist.clear();
	dist.resize(N + 1, INF);
	dist[X] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,X });
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (w > dist[v])
			continue;
		for (int i = 0; i < g[v][k].size(); i++) {
			int nw = w + g[v][k][i].first;
			int nv = g[v][k][i].second;
			if (dist[nv] <= nw)
				continue;
			dist[nv] = nw;
			pq.push({ nw,nv });
		}
	}
	for (int i = 1; i <= N; i++)
		ans[i] += dist[i];
}