#include <bits/stdc++.h>
using namespace std;

int A[1000], len1[1000], len2[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j, ans = 0;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
	for (i = 0; i < N; i++) {
		len1[i] = 1;
		for (j = 0; j < i; j++) {
			if (A[i] > A[j])
				len1[i] = max(len1[i], len1[j] + 1);
		}
	}

	for (i = N - 1; i >= 0; i--) {
		len2[i] = 1;
		for (j = N - 1; j > i; j--) {
			if (A[i] > A[j])
				len2[i] = max(len2[i], len2[j] + 1);
		}
	}
	for (i = 0; i < N; i++) {
		int sum = len1[i] + len2[i];
		if (sum > ans)
			ans = sum;
	}
	cout << ans - 1;
}