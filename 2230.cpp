#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
int A[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	if (!M)
		ans = 0;
	else {
		int l = 0, r = 0, dif;
		ans = 2000000000;
		while (r < N) {
			dif = A[r] - A[l];
			if (dif < ans && dif >= M) {
				ans = dif;
				l++;
			}
			else if (dif > M)
				l++;
			else
				r++;
		}
	}
	cout << ans;
}