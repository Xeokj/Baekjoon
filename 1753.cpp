#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
vector<edge> graph[20001];	// 그래프 정보
vector<int> dist;	// 최단 거리 저장
priority_queue < edge, vector<edge>, greater<edge>> pq;
// 가중치가 가장 적은게 top에 오도록 우선순위 큐 설정

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	
	dist.resize(V + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	dist[K] = 0;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}

	pq.push({ dist[K], K });	// 시작 지점 우선순위 큐에 넣음
	while (!pq.empty()) {
		edge cur = pq.top();	// 정점으로의 가중치가 가장 적은 Edge
		pq.pop();
		for (auto next : graph[cur.second]) {
			// 기존에 저장된 최단 경로가 더 적은 경우 패스
			if (dist[next.second] <= dist[cur.second] + next.first)
				continue;
			dist[next.second] = dist[cur.second] + next.first;
			pq.push({ dist[next.second],next.second });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << endl;
	}
}