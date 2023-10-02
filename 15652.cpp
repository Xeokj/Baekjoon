#include <bits/stdc++.h>
using namespace std;
// 백준 15652번: N과 M (4) (실버 3)
int arr[8];
int N, M;
void backtr(int cur, int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	backtr(1, 0);
}

void backtr(int cur, int num) {
	if (num == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = cur; i <= N; i++) {
		arr[num] = i;
		backtr(i, num + 1);
	}
}