#include <bits/stdc++.h>
using namespace std;

int graph[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j, k, tmp;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			cin >> tmp;
			if (!tmp)
				graph[i][j] = N + 1;
			else
				graph[i][j] = 1;
		}

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (graph[i][j] > 0 && graph[i][j] <= N)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}