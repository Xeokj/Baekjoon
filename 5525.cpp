#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i, ans = 0;
	string s;
	cin >> N >> M;
	cin >> s;
	for (i = 0; i < M - 2 * N; i++) {
		if (s[i] == 'I') {
			int cnt = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				cnt++;
				i += 2;
				if (cnt == N) {
					ans++;
					cnt--;
				}
			}
		}
	}
	cout << ans;
}