#include <bits/stdc++.h>
using namespace std;
vector<int> bot, top;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, H, h, i;
	cin >> N >> H;
	bot.resize(H + 1);
	top.resize(H + 1);
	for (i = 0; i < N; i++) {
		cin >> h;
		if (i % 2)
			top[h]++;
		else
			bot[h]++;
	}
	for (i = H - 1; i >= 0; i--) {
		bot[i] += bot[i + 1];
		top[i] += top[i + 1];
	}
	int sum, min = N, x = 0;
	for (i = 1; i <= H; i++) {
		sum = bot[i] + top[H - i + 1];
		if (sum < min) {
			min = sum;
			x = 1;
		}
		else if (sum == min)
			x++;
	}
	cout << min << ' ' << x;
}