#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, start = 0, end = 0, sum = 0, ans = 0;
	cin >> N;
	while (end <= N) {
		if (sum < N) {
			end++;
			sum += end;
		}
		else if (sum == N) {
			ans++;
			end++;
			sum += end;
		}
		else {
			start++;
			sum -= start;
		}
	}
	cout << ans;
}