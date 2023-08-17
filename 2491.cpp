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
			// 오름차순일 때
			if (d) {
				// 이전까지 내림차순이었을 때
				cnt = same + 1;
				d = 0;
				a = 1;
			}
			else
				cnt++;
			same = 1;
		}
		else if (num < prenum) {
			// 내림차순일 때
			if (a) {
				// 이전까지 오름차순이었을 때
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