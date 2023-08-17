#include <bits/stdc++.h>
using namespace std;
string input;
stack<char> s;
stack<char> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, i;
	cin >> N >> K >> input;
	for (i = 0; i < N; i++) {
		if (!K || s.empty()) {
			s.push(input[i]);
			continue;
		}
		while (input[i] > s.top()) {
			s.pop();
			K--;
			if (!K || s.empty())
				break;
		}
		s.push(input[i]);
	}
	while (K) {
		s.pop();
		K--;
	}
	while(!s.empty()){
		char a = s.top();
		s.pop();
		ans.push(a);
	}
	while (!ans.empty()) {
		char a = ans.top();
		ans.pop();
		cout << a;
	}
}