#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
vector<edge> graph[20001];	// �׷��� ����
vector<int> dist;	// �ִ� �Ÿ� ����
priority_queue < edge, vector<edge>, greater<edge>> pq;
// ����ġ�� ���� ������ top�� ������ �켱���� ť ����

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

	pq.push({ dist[K], K });	// ���� ���� �켱���� ť�� ����
	while (!pq.empty()) {
		edge cur = pq.top();	// ���������� ����ġ�� ���� ���� Edge
		pq.pop();
		for (auto next : graph[cur.second]) {
			// ������ ����� �ִ� ��ΰ� �� ���� ��� �н�
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