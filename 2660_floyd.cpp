#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, i, j, k;
	int con[51][51];
	cin >> n;
	fill(con[1] + 1, con[n] + n + 1, 51);
	for (i = 1; i <= n; i++)
		con[i][i] = 0;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		con[a][b] = 1;
		con[b][a] = 1;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				con[i][j] = min(con[i][j], con[i][k] + con[k][j]);
			}
		}
	}
	int score = 51, size;
	vector<int> nomi;
	for (i = 1; i <= n; i++) {
		int max = 0;
		for (j = 1; j <= n; j++) {
			if (con[i][j] > max)
				max = con[i][j];
		}
		if (max < score) {
			nomi.clear();
			score = max;
			nomi.push_back(i);
		}
		else if (max == score)
			nomi.push_back(i);
	}
	size = nomi.size();
	cout << score << ' ' << size << "\n";
	for (i = 0; i < size; i++) {
		cout << nomi[i] << ' ';
	}
}