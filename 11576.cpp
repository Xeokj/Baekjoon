#include <bits/stdc++.h>
using namespace std;
// ���� 11576��: Base Conversion (�ǹ� 5)
int before[25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A, B, n, i, j;
	cin >> A >> B >> n;
	for (i = 0; i < n; i++)
		cin >> before[i];
	int num = 0;
	for (i = 0, j = 1; i < n; i++, j *= A)
		num += before[n - 1 - i] * j;
	stack<int> s;
	while (num) {
		s.push(num % B);
		num /= B;
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}