#include <bits/stdc++.h>
using namespace std;
// 백준 28278번: 스택 2 (실버 4)
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, num, X;
	cin >> N;
	while (N--) {
		cin >> num;
		if (num == 1) {
			cin >> X;
			st.push(X);
		}
		else if (num == 2) {
			if (st.empty())
				cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (num == 3)
			cout << st.size() << "\n";
		else if (num == 4)
			cout << st.empty() << "\n";
		else if (num == 5) {
			if (st.empty())
				cout << -1 << "\n";
			else
				cout << st.top() << "\n";
		}
	}
}