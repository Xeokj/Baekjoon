#include <bits/stdc++.h>
using namespace std;
// 백준 2331번: 반복수열 (실버 4)
int D[236197];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A, P, order = 1;
	cin >> A >> P;
	do {
		D[A] = order;
		int next = 0;
		while (A) {
			int x = A % 10;
			int tmp = 1;
			for (int i = 0; i < P; i++)
				tmp *= x;
			next += tmp;
			A /= 10;
		}
		A = next;
		order++;
	} while (!D[A]);
	cout << D[A] - 1;
}