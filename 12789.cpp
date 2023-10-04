#include <bits/stdc++.h>
using namespace std;
// 백준 12789번: 도키도키 간식드리미 (실버 3)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, num, order = 1, i;
	cin >> N;
	stack<int> s;
	for (i = 0; i < N; i++) {
		cin >> num;
		if (num == order)
			order++;
		else if (s.empty())
			s.push(num);
		else {
			while (!s.empty() && order == s.top()) {
				s.pop();
				order++;
			}
			if (num == order)
				order++;
			else
				s.push(num);
		}
	}
	while (!s.empty() && order == s.top()) {
		s.pop();
		order++;
	}
	if (s.empty())
		cout << "Nice";
	else
		cout << "Sad";
}