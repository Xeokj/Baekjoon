#include <bits/stdc++.h>
using namespace std;

int N, del, ans;
vector<int> graph[50];
void DFS(int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int root, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == -1) {
			root = i;
			continue;
		}
		graph[num].push_back(i);
	}
	cin >> del;
	if (del != root) {
		DFS(root);
		cout << ans;
	}
	else
		cout << 0;
}

void DFS(int x) {
	int del_idx = -1;
	for (int i = 0; i < graph[x].size(); i++) {
		if (graph[x][i] == del) {
			del_idx = i;
			continue;
		}
		DFS(graph[x][i]);
	}
	if (del_idx > -1)
		graph[x].erase(graph[x].begin() + del_idx);
	if (graph[x].empty())
		ans++;
}