#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, prenum, num, cnt = 1, max = 1;
	cin >> N;
	int a = 1, d = 1, same = 1;
	cin >> prenum;
	for (int i = 1; i < N; i++) {
		cin >> num;
		if (num > prenum) {
			// ���������� ��
			if (d) {
				// �������� ���������̾��� ��
				cnt = same + 1;
				d = 0;
				a = 1;
			}
			else
				cnt++;
			same = 1;
		}
		else if (num < prenum) {
			// ���������� ��
			if (a) {
				// �������� ���������̾��� ��
				cnt = same + 1;
				a = 0;
				d = 1;
			}
			else
				cnt++;
			same = 1;
		}
		else {
			same++;
			cnt++;
		}
		if (cnt > max)
			max = cnt;
		prenum = num;
	}
	cout << max;
}