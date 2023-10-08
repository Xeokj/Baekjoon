#include <bits/stdc++.h>
using namespace std;
// 백준 1969번: DNA (실버 4)
int arr[50][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i, j, ans = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (j = 0; j < M; j++) {
			if (s[j] == 'A')
				arr[j][0]++;
			else if (s[j] == 'C')
				arr[j][1]++;
			else if (s[j] == 'G')
				arr[j][2]++;
			else
				arr[j][3]++;
		}
	}
	for (i = 0; i < M; i++) {
		int max = 0, max_idx;
		for (j = 0; j < 4; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				max_idx = j;
			}
		}
		ans += (N - max);
		if (max_idx == 0)
			cout << 'A';
		else if (max_idx == 1)
			cout << 'C';
		else if (max_idx == 2)
			cout << 'G';
		else if (max_idx == 3)
			cout << 'T';
	}
	cout << "\n" << ans;
}