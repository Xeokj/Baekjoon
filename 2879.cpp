#include <bits/stdc++.h>
using namespace std;
// 백준 2879번: 코딩은 예쁘게 (골드 3)
int diff[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, num, ans = 0, i, j, k;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> diff[i];
	for (i = 0; i < N; i++) {
		cin >> num;
		diff[i] = diff[i] - num;
	}
	bool flg = 1;
	while (flg) {
		flg = 0;
		for (i = 0; i < N; i++) {
			if (!diff[i])
				continue;
			flg = 1;
			int min = diff[i];
			for (j = i + 1; j <= N; j++) {
				if (diff[j] * diff[i] <= 0) {
					ans += abs(min);
					for (k = i; k < j; k++)
						diff[k] -= min;
					i = j - 1;
					break;
				}
				else {
					if (abs(diff[j]) < abs(min))
						min = diff[j];
				}
			}
		}
	}
	cout << ans;
}