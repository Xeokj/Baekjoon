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
			root = i;	// 루트 노드 번호 저장
			continue;
		}
		graph[num].push_back(i);
	}
	cin >> del;	// 삭제할 노드
	if (del != root) {
		DFS(root);
		cout << ans;
	}
	else
		cout << 0;	// root를 삭제하는 경우
}

void DFS(int x) {
	int del_idx = -1;
	for (int i = 0; i < graph[x].size(); i++) {
		if (graph[x][i] == del) {
			del_idx = i;	// 삭제할 노드 저장
			continue;	// 삭제할 노드는 탐색 X
		}
		DFS(graph[x][i]);
	}
	if (del_idx > -1)
		graph[x].erase(graph[x].begin() + del_idx);
	// 해당 노드로의 길 삭제
	if (graph[x].empty())
		ans++;	// 자식 노드가 없으면 리프 노드이므로
}