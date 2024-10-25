#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 11501번: 주식 (실버 2)
typedef long long ll;
int arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, N, i;
	cin >> T;
	while (T--) {
		cin >> N;
		for (i = 0; i < N; i++)
			cin >> arr[i];
		ll ans = 0;
		int max = arr[N - 1];
		for (i = N - 2; i >= 0; i--) {
			if (arr[i] > max)
				max = arr[i];
			else
				ans += (max - arr[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}