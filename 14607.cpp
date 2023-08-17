#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N, ans;
	cin >> N;
	ans = N * (N - 1) / 2;
	cout << ans;
}