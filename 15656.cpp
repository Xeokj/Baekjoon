#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9], ans[9];
void nm(int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	sort(arr, arr + N + 1);
	nm(1);
}

void nm(int num) {
	if (num > M) {
		for (int i = 1; i <= M; i++)
			cout << ans[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		ans[num] = arr[i];
		nm(num + 1);
	}
}