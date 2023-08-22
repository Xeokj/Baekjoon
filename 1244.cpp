#include <bits/stdc++.h>
using namespace std;
bool s[101];
int N, K, sex, num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int i, tmp, left, right;
	for (int i = 1; i <= N; i++)
		cin >> s[i];
	cin >> K;
	while (K--) {
		cin >> sex >> num;
		if (sex == 1) {
			tmp = 1;
			while (tmp * num <= N) {
				s[tmp * num] = !s[tmp * num];
				tmp++;
			}
		}
		else {
			s[num] = !s[num];
			for (left = num - 1, right = num + 1; left >= 1 && right <= N; left--, right++) {
				if (s[left] == s[right]) {
					s[left] = !s[left];
					s[right] = !s[right];
				}
				else
					break;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		cout << s[i] << ' ';
		if (i % 20 == 0)
			cout << "\n";
	}
}