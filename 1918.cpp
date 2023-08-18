#include <bits/stdc++.h>
using namespace std;
stack<char> s;
string input;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			cout << input[i];	// 알파벳은 바로 출력
		else if (s.empty() || input[i] == '(')
			s.push(input[i]);	// 스택이 비었거나 괄호는 바로 넣어줌
		else if (input[i] == '+' || input[i] == '-') {
			// + 와 - 보다 우선순위가 더 높은 것은 '('를 제외한 모든 연산 기호
			// 이전에 있던 + 또는 - 은 우선순위가 더 높으므로
			while (!s.empty() && s.top() != '(') {
				// 스택이 빌 때까지 또는 '('가 나오기 전까지 모두 꺼내줌
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);	// 스택에 넣음
		}
		else if (input[i] == '*' || input[i] == '/') {
			// * 와 / 보다 우선순위가 더 높은 것은 이전에 있던 * 또는 / 밖에 없음
			if (s.top() == '*' || s.top() == '/') {
				// 따라서 이전에 * 또는 / 가 있으면 꺼내줌
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);	// 스택에 넣음
		}
		else if (input[i] == ')') {
			while (s.top() != '(') {
				// '(' 전까지 스택에서 꺼내줌 
				cout << s.top();
				s.pop();
			}
			s.pop();	// '('도 스택에서 꺼내줌
		}
	}
	while (!s.empty()) {
		// 스택에 남아 있는 것 꺼내줌
		cout << s.top();
		s.pop();
	}
}