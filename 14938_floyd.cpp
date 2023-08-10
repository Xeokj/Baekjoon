#include <bits/stdc++.h>
#define INF 1500
using namespace std;
int n, m, r;
int items[101];
int graph[101][101];
// Floyd-Warshall

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, l, i, j, k;
	cin >> n >> m >> r;
	for (i = 1; i <= n; i++)
		cin >> items[i];
	for (i = 1; i <= n; i++) {
		fill(graph[i], graph[i] + n + 1, INF);
		graph[i][i] = 0;
	}
	for (i = 0; i < r; i++) {
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int sum, ans = 0;
	for (i = 1; i <= n; i++) {
		sum = 0;
		for (j = 1; j <= n; j++) {
			if (graph[i][j] <= m)
				sum += items[j];
		}
		if (sum > ans)
			ans = sum;
	}
	cout << ans;
}