#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
string input, bomb;
stack<char> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> input >> bomb;
	int ilen = input.length(), blen = bomb.length();
	for (int i = 0; i < ilen; i++) {
		int r = blen - 1;
		st.push(input[i]);
		if (st.top() == bomb[r]) {
			// bomb의 끝 문자부터 스택의 top과 비교함
			while (r >= 0 && !st.empty() && st.top() == bomb[r]) {
				st.pop();
				r--;
			}
			if (r != -1) {
				// bomb과 같지 않으면 꺼냈던거 다시 집어 넣기
				while (r < blen - 1) {
					r++;
					st.push(bomb[r]);
				}
			}
		}
	}
	if (st.empty())
		cout << "FRULA";
	else {
		string ans = "";
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		for (int i = ans.length() - 1; i >= 0; i--)
			cout << ans[i];		
	}
}