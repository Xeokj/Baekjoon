#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, tmp1, tmp2, i;
	cin >> N >> K >> tmp1;
	vector<int> diff;
	for (i = 1; i < N; i++) {
		cin >> tmp2;
		diff.push_back(tmp2 - tmp1);
		tmp1 = tmp2;
	}
	sort(diff.begin(), diff.end());
	int ans = 0;
	for (i = 0; i < N - K; i++)
		ans += diff[i];
	cout << ans;
}