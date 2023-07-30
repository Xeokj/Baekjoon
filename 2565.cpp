#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, i, j;
	vector<pair<int, int>> line;
	int lis[100];
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		line.push_back(make_pair(a, b));
	}
	sort(line.begin(), line.end());
	int Max = 0;
	for (i = 0; i < N; i++) {
		lis[i] = 1;
		for (j = 0; j < i; j++) {
			if (line[i].second > line[j].second)
				lis[i] = max(lis[i], lis[j] + 1);
		}
		if (lis[i] > Max)
			Max = lis[i];
	}
	cout << N - Max;
}