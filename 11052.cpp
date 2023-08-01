#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	int P[1001];
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> P[i];
	for (i = 2; i <= N; i++) {
		int Max = 0;
		for (j = 1; j <= i / 2; j++) {
			int tmp = P[j] + P[i - j];
			if (tmp > Max)
				Max = tmp;
		}
		P[i] = max(P[i], Max);
	}
	cout << P[N];
}