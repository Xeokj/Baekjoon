#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8], visited[8], ans[8];
void backtr(int cur, int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	backtr(0, 0);
}

void backtr(int cur, int num) {
	int i;
	if (num == M) {
		int same = 0;
		for (i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << "\n";
		return;
	}
	for (i = cur; i < N; i++) {
		if (!visited[i]) {
			ans[num] = arr[i];
			backtr(i + 1, num + 1);
			// 다음 번에는 방금 선택한 수와 다른 수를 선택하도록 커서 이동
			while (arr[i] == arr[i + 1])
				i++;
		}
	}
}