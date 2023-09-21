#include <bits/stdc++.h>
using namespace std;
// 백준 12904번: A와 B (골드 5)
string A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	int st = 0, en = B.size() - 1;
	int i, tmp;
	while (abs(en - st) + 1 > A.size()) {
		if (B[en] == 'B') {
			if (st < en)
				en--;
			else
				en++;
			tmp = st;
			st = en;
			en = tmp;
		}
		else {
			if (st < en)
				en--;
			else
				en++;
		}
	}
	for (i = 0; i < A.size(); i++) {
		if (A[i] != B[st])
			break;
		if (st < en)
			st++;
		else
			st--;
	}
	if (i == A.size())
		cout << 1;
	else
		cout << 0;
}