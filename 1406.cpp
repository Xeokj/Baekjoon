#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// ���� 1406��: ������ (�ǹ� 2)
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
			// L�� ��
			if (!left.empty()) {
				// left�� top�� right�� push ���ش�.
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			// D�� ��
			if (!right.empty()) {
				// right�� top�� left�� push ���ش�.
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			// B�� ��
			if (!left.empty())
				left.pop();
		}
		else if (cmd == 'P') {
			// P�� ��
			char c;
			cin >> c;
			left.push(c);
		}
	}
	// stack�� index�� ������ �� ���� ������ �Ʒ�ó�� left�� ��� right�� �Ű��� �� ����Ѵ�.
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		// right�� top���� �Ųٷ� ������ش�.
		cout << right.top();
		right.pop();
	}
	return 0;
}