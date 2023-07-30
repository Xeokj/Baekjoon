#include <bits/stdc++.h>
using namespace std;

int space[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i, j;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cin >> space[i][j];

	int sum = N * M * 2;	// À­¸é, ¹Ù´Ú
	// ÀÎÁ¢ÇÑ ¸éº¸´Ù ´õ ³ôÀ¸¸é °Ñ³ÐÀÌ Áõ°¡
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (space[i][j] > space[i - 1][j])
				sum += space[i][j] - space[i - 1][j];
			if (space[i][j] > space[i + 1][j])
				sum += space[i][j] - space[i + 1][j];
		}
	}
	for (j = 1; j <= M; j++) {
		for (i = 1; i <= N; i++) {
			if (space[i][j] > space[i][j - 1])
				sum += space[i][j] - space[i][j - 1];
			if (space[i][j] > space[i][j + 1])
				sum += space[i][j] - space[i][j + 1];
		}
	}
	cout << sum;
}