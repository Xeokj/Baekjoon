#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	int A[1000], len[1000], ans[1000];
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
	// LIS 구하기
	for (i = 0; i < N; i++) {
		len[i] = 1;
		for (j = 0; j < i; j++) {
			if (A[i] > A[j])
				len[i] = max(len[i], len[j] + 1);
		}
	}
	// 길이가 가장 긴 곳의 위치 찾기
	int maxlen = 0, maxidx;
	for (i = 0; i < N; i++)
		if (len[i] > maxlen) {
			maxlen = len[i];
			maxidx = i;
		}
	// 경로 추적
	ans[0] = A[maxidx];
	int l = maxlen - 1;
	for (i = maxidx - 1, j = 0; i >= 0; i--) {
		if (len[i] == l && A[i] < ans[j]) {
			ans[++j] = A[i];
			l--;
		}
	}
	cout << maxlen << "\n";
	for (i = maxlen - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}