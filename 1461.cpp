#include <bits/stdc++.h>
using namespace std;
// 백준 1461번: 도서관 (골드 4)
vector<int> neg, pos;	// 음수, 양수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, num, i, ans = 0;
	cin >> N >> M;
	while (N--) {
		cin >> num;
		if (num > 0)
			pos.push_back(num);
		else {
			num = (-num);
			neg.push_back(num);
		}
	}
	int nneg = neg.size();
	int npos = pos.size();
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	for (i = nneg - 1; i >= 0; i -= M)
		ans += neg[i] * 2;
	for (i = npos - 1; i >= 0; i -= M)
		ans += pos[i] * 2;
	if (nneg > 0 && npos > 0) {
		if (neg[nneg - 1] > pos[npos - 1])
			ans -= neg[nneg - 1];
		else
			ans -= pos[npos - 1];
	}
	else if (nneg > 0) {
		ans -= neg[nneg - 1];
	}
	else
		ans -= pos[npos - 1];
	cout << ans;
}