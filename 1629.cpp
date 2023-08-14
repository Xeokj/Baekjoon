#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long A, B, C, tA, tB, ans = 1;
	cin >> A >> B >> C;
	while (B) {
		if (B == 1) {
			ans = (ans * A) % C;
			break;
		}
		tA = A;
		for (tB = 2; tB <= B; tB *= 2) {
			tA = (tA * tA) % C;
		}
		ans = (ans * tA) % C;
		tB /= 2;
		B -= tB;
	}
	cout << ans;
}