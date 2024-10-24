#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 백준 2564번: 경비원 (실버 1)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, y, n, i;
	cin >> x >> y >> n;
	int perimeter = 2 * (x + y);

	vector<pair<int, int>> coord;
	int dir, loc;
	for (i = 0; i <= n; i++) {
		cin >> dir >> loc;
		coord.push_back({ dir,loc });
	}
	// coord의 마지막 원소는 동근이의 위치
	int ddir = coord[n].first, dloc = coord[n].second;
	int ans = 0, len;
	for (i = 0; i < n; i++) {
		if (coord[i].first == ddir)
			len = abs(coord[i].second - dloc);
		else if (coord[i].first == 1) {
			if (ddir == 2) {
				len = y + coord[i].second + dloc;
				len = min(len, perimeter - len);
			}
			else if (ddir == 3)
				len = dloc + coord[i].second;
			else
				len = dloc + (x - coord[i].second);			
		}
		else if (coord[i].first == 2) {
			if (ddir == 1) {
				len = y + coord[i].second + dloc;
				len = min(len, perimeter - len);
			}
			else if (ddir == 3)
				len = dloc + (y - coord[i].second);
			else
				len = (x - dloc) + (y - coord[i].second);
		}
		else if (coord[i].first == 3) {
			if (ddir == 4) {
				len = x + coord[i].second + dloc;
				len = min(len, perimeter - len);
			}
			else if (ddir == 1)
				len = dloc + coord[i].second;
			else
				len = dloc + (y - coord[i].second);
		}
		else {
			if (ddir == 3) {
				len = x + coord[i].second + dloc;
				len = min(len, perimeter - len);
			}
			else if (ddir == 1)
				len = (x - dloc) + coord[i].second;
			else
				len = (x - dloc) + (y - coord[i].second);
		}
		ans += len;
	}
	cout << ans;
	return 0;
}