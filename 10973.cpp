#include <bits/stdc++.h>
using namespace std;
int arr[10000], visited[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	cin >> N;
	fill(visited, visited + N + 1, 1);
	for (i = 0; i < N; i++)
		cin >> arr[i];
	bool flg = 0;
	for (i = N - 1; i >= 0; i--) {
		int num = arr[i];
		visited[num] = 0;
		for (j = num - 1; j > 0; j--) {
			if (!visited[j]) {
				arr[i] = j;
				visited[j] = 1;
				flg = 1;
				break;
			}
		}
		if (flg)
			break;
	}
	if (i == -1)
		cout << -1;
	else {
		i++;
		for (j = N; j > 0; j--) {
			if (!visited[j]) {
				arr[i] = j;
				visited[j] = 1;
				i++;
			}
		}
		for (i = 0; i < N; i++)
			cout << arr[i] << ' ';
	}
}