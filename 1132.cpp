#include <bits/stdc++.h>
using namespace std;
// ���� 1132��: �� (��� 3)
long long alpha[10];	// alpha[0]: A, alpha[1]: B, ... , alpha[9]: J
long long ans;
bool notzero[10];	// 0�̸� �ȵǴ� ���ĺ� = 1

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		string input;
		cin >> input;
		notzero[input[0] - 'A'] = 1;	// ù ��° �ڸ��� �ִ� ���ĺ��� 0�� �Ǹ� �� ��
		long long k = 1;
		for (j = input.size() - 1; j >= 0; j--) {
			alpha[input[j] - 'A'] += k;
			k *= 10;
		}
	}
	bool flg = 0;
	for (i = 0; i < 10; i++)
		if (!alpha[i])
			flg = 1;
	if (!flg) {
		// A���� J������ ��� ���ĺ��� ���� ��쿡�� ��򰡿� 0�� ��� ��
		// 0�� �ǵ� ������ �� �� ���� ���� �Ϳ� 0�� ����
		long long min = 10000000000000000;
		int idx;	// 0�� ������ ���ĺ� index
		for (i = 0; i < 10; i++) {
			if (!notzero[i] && alpha[i] < min) {
				min = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;	// ���� ���� �Ϳ� 0 ����
	}
	sort(alpha, alpha + 10, greater<>());	// �������� ����
	for (i = 0, j = 9; i < 10; i++, j--)
		ans += alpha[i] * j;	// �� ���� ����
	cout << ans;
}