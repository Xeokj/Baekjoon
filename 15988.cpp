#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 15988번: 1, 2, 3 더하기 3 (실버 2)
long long arr[1000001] = { 0,1,2,4 };
int T, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int i = 4; i <= 1000000; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000009;
	while (T--) {
		cin >> n;
		cout << arr[n] << "\n";
	}
	return 0;
}