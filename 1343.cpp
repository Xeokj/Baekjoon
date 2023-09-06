#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string board, ans = "";
	cin >> board;
	int size = board.size();
	int a, b, cnt = 0;
	for (int i = 0; i < size; i++) {
		if (board[i] == '.') {
			if (cnt % 2)
				break;
			a = cnt / 4;
			for (int j = 0; j < a; j++)
				ans += "AAAA";
			b = cnt % 4;
			if (b)
				ans += "BB";
			ans += '.';
			cnt = 0;
		}
		else
			cnt++;
	}
	if (cnt % 2)
		cout << -1;
	else {
		a = cnt / 4;
		for (int j = 0; j < a; j++)
			ans += "AAAA";
		b = cnt % 4;
		if (b)
			ans += "BB";
		cout << ans;
	}
}