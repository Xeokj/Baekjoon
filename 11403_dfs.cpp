#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int visited[100];
void DFS(int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j, tmp;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp)
				graph[i].push_back(j);
		}

	for (i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		DFS(i);
		for (j = 0; j < N; j++)
			cout << visited[j] << ' ';
		cout << "\n";
	}
}

void DFS(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		if (!visited[graph[x][i]]) {
			visited[graph[x][i]] = 1;
			DFS(graph[x][i]);
		}
	}
}