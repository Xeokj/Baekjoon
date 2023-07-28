#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A, B, cnt = 1;
	cin >> A >> B;
	while (B > A) {
		if (B % 2 == 0) {
			B /= 2;
			cnt++;
		}
		else if (B % 10 == 1) {
			B /= 10;
			cnt++;
		}
		else
			break;
	}
	if (A == B)
		cout << cnt;
	else
		cout << -1;
}