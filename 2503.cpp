#include <bits/stdc++.h>
using namespace std;
// ���� 2503��: ���� �߱� (�ǹ� 3)
/*
	123���� 987������ ���� ����� ������ �����ϴ� ���� ���� ���
*/
int used[10], num[100][3], st[100], ba[100];
int N, ans;
vector<string> arr;
int checknum(int a, int b, int c);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int i, j, k, n;
	for (i = 0; i < N; i++) {
		cin >> n;
		for (j = 2; j >= 0; j--) {
			num[i][j] = n % 10;
			n /= 10;
		}
		cin >> st[i] >> ba[i];
	}
	for (i = 1; i < 10; i++) {
		used[i] = 1;
		for (j = 1; j < 10; j++) {
			if (used[j])
				continue;
			used[j] = 1;
			for (k = 1; k < 10; k++) {
				if (used[k])
					continue;
				used[k] = 1;
				if (checknum(i, j, k))
					ans++;
				used[k] = 0;
			}
			used[j] = 0;
		}
		used[i] = 0;
	}
	cout << ans;
}

int checknum(int a, int b, int c) {
	int i, cnt = 0;
	for (i = 0; i < N; i++) {
		int ball = 0, strike = 0;
		if (num[i][0] == a)
			strike++;
		else if (used[num[i][0]])
			ball++;
		if (num[i][1] == b)
			strike++;
		else if (used[num[i][1]])
			ball++;
		if (num[i][2] == c)
			strike++;
		else if (used[num[i][2]])
			ball++;
		if (strike == st[i] && ball == ba[i])
			cnt++;
	}
	if (cnt == N)
		return 1;
	else
		return 0;
}