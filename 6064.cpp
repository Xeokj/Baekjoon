#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n, x, y, T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> x >> y;
		int a = x, b = y, max = m;
		if (n > m)
			max = n;
		
		int* arr = new int[max + 1]{};

		// a를 b로 만들기
		int flag = 0, ans = a;
		arr[a] = 1;

		a = a % n;
		if (!a)
			a = n;

		while (a != b) {
			a = (a + m) % n;
			if (!a)
				a = n;
			ans += m;
			if (arr[a]) {
				flag = 1;
				break;
			}
			arr[a] = 1;
		}

		if (flag)
			cout << -1 << endl;
		else
			cout << ans << endl;
		delete[] arr;
	}
}