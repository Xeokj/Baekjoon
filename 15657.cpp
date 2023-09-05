#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8], ans[8];
void NnM(int cur, int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	NnM(0, 0);
}

void NnM(int cur, int num) {
	if (num == M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = cur; i < N; i++) {
		ans[num] = arr[i];
		NnM(i, num + 1);
	}
}