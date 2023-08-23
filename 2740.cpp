#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> A, B, C;
int N, M, K;
int cal(int a, int b);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	A.resize(N);
	int i, j;
	for (i = 0; i < N; i++) {
		A[i].resize(M);
		for (j = 0; j < M; j++)
			cin >> A[i][j];
	}
	cin >> M >> K;
	B.resize(M);
	for (i = 0; i < M; i++) {
		B[i].resize(K);
		for (j = 0; j < K; j++)
			cin >> B[i][j];
	}
	// 계산
	C.resize(N);
	for (i = 0; i < N; i++) {
		C[i].resize(K);
		for (j = 0; j < K; j++) {
			C[i][j] = cal(i, j);
		}
	}
	// 출력
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++)
			cout << C[i][j] << ' ';
		cout << "\n";
	}
}

int cal(int a, int b) {
	int sum = 0;
	for (int i = 0; i < M; i++)
		sum += (A[a][i] * B[i][b]);
	return sum;
}