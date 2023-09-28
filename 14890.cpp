#include <bits/stdc++.h>
using namespace std;
// 백준 14890번: 경사로 (골드 3)
int arr[100][100], used[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, L, ans = 0, i, j, k;
	cin >> N >> L;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> arr[i][j];
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (abs(arr[i][j] - arr[i][j + 1]) > 1)
				break;
			bool flg = 0;
			if (arr[i][j] == arr[i][j + 1] - 1) {
				for (k = 0; k < L; k++) {
					if (j - k < 0) {
						flg = 1;
						break;
					}
					if (arr[i][j] != arr[i][j - k] || used[i][j - k]) {
						flg = 1;
						break;
					}
					used[i][j - k] = 1;
				}
				if (flg)
					break;
			}
			else if (arr[i][j] == arr[i][j + 1] + 1) {
				for (k = 1; k <= L; k++) {
					if (j + k >= N) {
						flg = 1;
						break;
					}
					if (arr[i][j + 1] != arr[i][j + k]) {
						flg = 1;
						break;
					}
					used[i][j + k] = 1;
				}
				if (flg)
					break;
				if (j + L == N - 1)
					j = N - 2;
				else if (arr[i][j + L] == arr[i][j + L + 1])
					j = j + L;
				else if (arr[i][j + L] != arr[i][j + L + 1])
					j = j + L - 1;
			}
		}
		if (j == N - 1)
			ans++;
	}
	memset(used, 0, sizeof(used));
	for (j = 0; j < N; j++) {
		for (i = 0; i < N - 1; i++) {
			if (abs(arr[i][j] - arr[i + 1][j]) > 1)
				break;
			bool flg = 0;
			if (arr[i][j] == arr[i + 1][j] - 1) {
				for (k = 0; k < L; k++) {
					if (i - k < 0) {
						flg = 1;
						break;
					}
					if (arr[i][j] != arr[i - k][j] || used[i - k][j]) {
						flg = 1;
						break;
					}
					used[i - k][j] = 1;
				}
				if (flg)
					break;
			}
			else if (arr[i][j] == arr[i + 1][j] + 1) {
				for (k = 1; k <= L; k++) {
					if (i + k >= N) {
						flg = 1;
						break;
					}
					if (arr[i + 1][j] != arr[i + k][j]) {
						flg = 1;
						break;
					}
					used[i + k][j] = 1;
				}
				if (flg)
					break;
				if (i + L == N - 1)
					i = N - 2;
				else if (arr[i + L][j] == arr[i + L + 1][j])
					i = i + L;
				else if (arr[i + L][j] != arr[i + L + 1][j])
					i = i + L - 1;
			}
		}
		if (i == N - 1)
			ans++;
	}
	cout << ans;
}