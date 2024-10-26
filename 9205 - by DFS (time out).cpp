#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// ���� 9205��: ���� ���ø鼭 �ɾ�� (��� 5)
// DFS�� Ǯ�� �ð��ʰ� ��

bool visited[100];
int t, n;
int dfs(int x, int y, int enx, int eny, vector<pair<int, int>> loc);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int stx, sty, enx, eny;
		vector<pair<int, int>> loc;
		memset(visited, 0, sizeof(visited));

		cin >> stx >> sty;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			loc.push_back({ x,y });
		}
		cin >> enx >> eny;

		if (dfs(stx, sty, enx, eny, loc))
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}

int dfs(int x, int y, int enx, int eny, vector<pair<int,int>> loc) {
	if (abs(x - enx) + abs(y - eny) <= 1000)
		return 1;	// ���� ��ġ���� ������������ �Ÿ��� 1000 ������ ��
	
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;	// �湮�� ���� ��
		if (abs(x - loc[i].first) + abs(y - loc[i].second) > 1000)
			continue;	// �Ÿ��� 1000�� ���� ��
		visited[i] = 1;
		if (dfs(loc[i].first, loc[i].second, enx, eny, loc))
			return 1;	// �������� ������ ��
		visited[i] = 0;	// �������� �������� ������ ��
	}
	return 0;	// �������� �������� ������ ��
}