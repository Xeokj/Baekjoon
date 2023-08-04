#include <bits/stdc++.h>
using namespace std;

vector<int> con[51];
vector<pair<int,int>> ans;
queue<pair<int,int>> q;
void BFS(int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, i;
	cin >> n;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	for (i = 1; i <= n; i++)
		BFS(i);
	sort(ans.begin(), ans.end());
	int min = ans[0].first, cnt = 1;
	for (i = 1; i < ans.size(); i++) {
		if (ans[i].first == ans[0].first)
			cnt++;
		else
			break;
	}
	cout << min << ' ' << cnt << "\n";
	for (i = 0; i < cnt; i++)
		cout << ans[i].second << ' ';
}

void BFS(int x) {
	if (con[x].empty())
		return;
	int visited[51] = {0};
	visited[x] = 1;
	q.push(make_pair(x, 0));
	int max = 0;
	while (!q.empty()) {
		int num = q.front().first;
		int score = q.front().second;
		if (score > max)
			max = score;
		q.pop();
		for (int i = 0; i < con[num].size(); i++) {
			int conn = con[num][i];
			if (!visited[conn]) {
				visited[conn] = 1;
				q.push(make_pair(conn, score + 1));
			}
		}
	}
	ans.push_back(make_pair(max, x));
}