#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8], visited[8], ans[8];
void backtr(int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	backtr(0);
}

void backtr(int num) {
	int i;
	if (num == M) {
		int same = 0;
		for (i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << "\n";
		return;
	}
	for (i = 0; i < N; i++) {
		if (!visited[i]) {
			ans[num] = arr[i];
			backtr(num + 1);
			while (arr[i] == arr[i + 1])
				i++;
		}
	}
}