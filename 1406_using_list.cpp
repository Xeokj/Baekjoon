#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// ���� 1406��: ������ (�ǹ� 2)
// List ���

string str;
int M;
char cmd;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str >> M;
	list<char> li(str.begin(), str.end());
	auto cur = li.end();

	while (M--) {
		cin >> cmd;
		if (cmd == 'L') {
			// L�� ��
			if (cur != li.begin())
				cur--;
		}
		else if (cmd == 'D') {
			// D�� ��
			if (cur != li.end())
				cur++;
		}
		else if (cmd == 'B') {
			// B�� ��
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
				// erase�� �ϰ� ���� iterator�� erase�ϱ� ���� ���� index�� ����Ų��.
				// ���� ��� list<int> li = {1,2}���� iterator itr�� 2�� ����Ű�� �־��ٸ�,
				// li.erase(itr)�� �ϰ��� itr�� li.end()�� ����Ų��.
				// ���� erase�� insert�� �ٸ��� ������ ������ �� iterator�� return�Ѵ�.
				// �̶� li.end()�� li�� ������ ���Ҵ� �ٸ���.
				// li.end()�� ����Ʈ�� ���� ����Ű�� "�� �̻� ���Ұ� ���� ��ġ"�� ��Ÿ����.
			}
		}
		else if (cmd == 'P') {
			// P�� ��
			char c;
			cin >> c;
			li.insert(cur, c);
			// insert�� �ϰ� ���� iterator�� insert�ϱ� ���� ����Ű�� ���� ����Ų��.
		}
	}
	for (auto c : li) {
		cout << c;
	}
	return 0;
}