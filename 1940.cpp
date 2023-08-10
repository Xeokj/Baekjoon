#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, num;
	cin >> n >> m;
	vector<int> A;
	for (int i = 0; i < n; i++) {
		cin >> num;
		A.push_back(num);
	}
	sort(A.begin(), A.end());
	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		if (A[l] + A[r] > m)
			r--;
		else if (A[l] + A[r] == m) {
			ans++;
			l++;
			r--;
		}
		else
			l++;
	}
	cout << ans;
}