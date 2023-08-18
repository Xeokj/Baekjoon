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
			cout << input[i];	// ���ĺ��� �ٷ� ���
		else if (s.empty() || input[i] == '(')
			s.push(input[i]);	// ������ ����ų� ��ȣ�� �ٷ� �־���
		else if (input[i] == '+' || input[i] == '-') {
			// + �� - ���� �켱������ �� ���� ���� '('�� ������ ��� ���� ��ȣ
			// ������ �ִ� + �Ǵ� - �� �켱������ �� �����Ƿ�
			while (!s.empty() && s.top() != '(') {
				// ������ �� ������ �Ǵ� '('�� ������ ������ ��� ������
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);	// ���ÿ� ����
		}
		else if (input[i] == '*' || input[i] == '/') {
			// * �� / ���� �켱������ �� ���� ���� ������ �ִ� * �Ǵ� / �ۿ� ����
			if (s.top() == '*' || s.top() == '/') {
				// ���� ������ * �Ǵ� / �� ������ ������
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);	// ���ÿ� ����
		}
		else if (input[i] == ')') {
			while (s.top() != '(') {
				// '(' ������ ���ÿ��� ������ 
				cout << s.top();
				s.pop();
			}
			s.pop();	// '('�� ���ÿ��� ������
		}
	}
	while (!s.empty()) {
		// ���ÿ� ���� �ִ� �� ������
		cout << s.top();
		s.pop();
	}
}