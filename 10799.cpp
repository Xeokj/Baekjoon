#include <bits/stdc++.h>
using namespace std;
string input;
stack<char> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, j, ans = 0;
	cin >> input;
	for (i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			if (input[i - 1] == '(') {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}