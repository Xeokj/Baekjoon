#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
int D, N;
int oven[300001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int min = INF, l, i, j;
	cin >> D >> N;
	for (i = 1; i <= D; i++) {
		cin >> l;
		if (l < min)
			min = l;
		oven[i] = min;
	}
	int pizza, deep = D;
	for (i = 0; i < N; i++) {
		cin >> pizza;
		while (deep > 0 && oven[deep] < pizza)
			deep--;
		deep--;
	}
	if (deep < 0)
		cout << 0;
	else
		cout << deep + 1;
}