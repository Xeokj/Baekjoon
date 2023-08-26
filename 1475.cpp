#include <bits/stdc++.h>
using namespace std;
string N;
int num[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int len = N.length();
	for (int i = 0; i < len; i++)
		num[N[i] - '0']++;
	int max = (num[6] + num[9] + 1) / 2;
	for (int i = 0; i < 9; i++) {
		if (i == 6)
			continue;
		if (num[i] > max)
			max = num[i];
	}
	cout << max;
}