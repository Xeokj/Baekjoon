#include <bits/stdc++.h>
using namespace std;
// ���� 2559��: ���� (�ǹ� 3)
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, i, ans = -INT_MAX;
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (i = K; i <= N; i++) {
		if (arr[i] - arr[i - K] > ans)
			ans = arr[i] - arr[i - K];
	}
	cout << ans;
}