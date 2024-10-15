#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 16926번: 배열 돌리기 1 (골드 5)
int N, M, R, Min;
int arr[300][300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	while (R--) {
		Min = min(N, M);
		for (int num = 0; num < Min / 2; num++) {
			int tmp = arr[num][num];
			for (int j = num; j < M - num - 1; j++)
				arr[num][j] = arr[num][j + 1];
			for (int i = num; i < N - num - 1; i++)
				arr[i][M - num - 1] = arr[i + 1][M - num - 1];
			for (int j = M - num - 1; j > num; j--)
				arr[N - num - 1][j] = arr[N - num - 1][j - 1];
			for (int i = N - num - 1; i > num; i--)
				arr[i][num] = arr[i - 1][num];
			arr[num + 1][num] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}