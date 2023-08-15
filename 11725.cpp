#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, i;
	cin >> N;
	tree.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1, 0);
	for (i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	// BFS
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (i = 0; i < tree[v].size(); i++) {
			int nv = tree[v][i];
			if (!visited[nv]) {
				parent[nv] = v;
				q.push(nv);
				visited[nv] = 1;
			}
		}
	}
	for (i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}