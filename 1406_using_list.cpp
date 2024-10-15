#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 1406번: 에디터 (실버 2)
// List 사용

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
			// L일 때
			if (cur != li.begin())
				cur--;
		}
		else if (cmd == 'D') {
			// D일 때
			if (cur != li.end())
				cur++;
		}
		else if (cmd == 'B') {
			// B일 때
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
				// erase를 하고 나면 iterator는 erase하기 전과 같은 index를 가리킨다.
				// 예를 들어 list<int> li = {1,2}에서 iterator itr가 2를 가리키고 있었다면,
				// li.erase(itr)를 하고나면 itr는 li.end()를 가리킨다.
				// 또한 erase는 insert와 다르게 삭제를 수행한 후 iterator를 return한다.
				// 이때 li.end()와 li의 마지막 원소는 다르다.
				// li.end()는 리스트의 끝을 가리키는 "더 이상 원소가 없는 위치"를 나타낸다.
			}
		}
		else if (cmd == 'P') {
			// P일 때
			char c;
			cin >> c;
			li.insert(cur, c);
			// insert를 하고 나면 iterator는 insert하기 전에 가리키던 값을 가리킨다.
		}
	}
	for (auto c : li) {
		cout << c;
	}
	return 0;
}