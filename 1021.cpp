#include <bits/stdc++.h>
using namespace std;
// 백준 1021번: 회전하는 큐 (실버 3)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, num, ans = 0, i, j;
	deque<int> dq;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		dq.push_back(i);
	while (M--) {
		cin >> num;
		for (i = 0; i < dq.size(); i++) {
			if (dq[i] == num)
				break;
		}
		int tmp;
		if (i < (dq.size() + 1) / 2) {
			for (j = 0; j < i; j++) {
				tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				ans++;
			}
		}
		else {
			for (j = dq.size() - 1; j >= i; j--) {
				tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				ans++;
			}
		}
		dq.pop_front();
	}
	cout << ans;
}