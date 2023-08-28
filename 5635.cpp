#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int ymax = 1989, mmax = 0, dmax = 0;
	int ymin = 2011, mmin = 13, dmin = 32;
	string max, min;
	cin >> n;
	while (n--) {
		string name;
		int d, m, y;
		cin >> name >> d >> m >> y;
		if (y < ymin) {
			ymin = y;
			mmin = m;
			dmin = d;
			min = name;
		}
		else if (y == ymin) {
			if (m > mmin)
				continue;
			if (m == mmin && d > dmin)
				continue;
			ymin = y;
			mmin = m;
			dmin = d;
			min = name;			
		}
		if (y > ymax) {
			ymax = y;
			mmax = m;
			dmax = d;
			max = name;
		}
		else if (y == ymax) {
			if (m < mmax)
				continue;
			if (m == mmax && d < dmax)
				continue;
			ymax = y;
			mmax = m;
			dmax = d;
			max = name;
		}
	}
	cout << max << "\n" << min;
}