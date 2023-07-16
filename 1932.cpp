#include <bits/stdc++.h>
using namespace std;

int previ[501], pres[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, i, k;
	cin >> n;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= k; i++) {
			cin >> pres[i];
			pres[i] = max(previ[i - 1], previ[i]) + pres[i];
		}
		copy(begin(pres), end(pres), begin(previ));
	}
	cout << *max_element(begin(pres),end(pres));
}