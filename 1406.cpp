#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 1406번: 에디터 (실버 2)
string str;
int M;
char cmd;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<char> left;
	stack<char> right;
	cin >> str >> M;

	for (auto c : str)
		left.push(c);

	while (M--) {
		cin >> cmd;
		if (cmd == 'L') {
			// L일 때
			if (!left.empty()) {
				// left의 top을 right에 push 해준다.
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			// D일 때
			if (!right.empty()) {
				// right의 top을 left에 push 해준다.
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			// B일 때
			if (!left.empty())
				left.pop();
		}
		else if (cmd == 'P') {
			// P일 때
			char c;
			cin >> c;
			left.push(c);
		}
	}
	// stack은 index로 접근할 수 없기 때문에 아래처럼 left를 모두 right로 옮겨준 후 출력한다.
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		// right의 top부터 거꾸로 출력해준다.
		cout << right.top();
		right.pop();
	}
	return 0;
}