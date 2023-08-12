#include <bits/stdc++.h>
#define MAX 1100000
using namespace std;
bool A[MAX] = {1,1,0};
int main() {
	int N, i, j;
	cin >> N;
	// �����佺�׳׽��� ü
	for (i = 2; i <= sqrt(MAX); i++) {
		for (j = 2; i * j <= MAX; j++)
			A[i * j] = 1;
	}
	for (i = N; i < MAX; i++) {
		if (!A[i]) {
			// i�� �� �ڸ� ������ �ľ�
			int len = 7, w = 1000000;
			while (!(i / w)) {
				w /= 10;
				len--;
			}
			vector<int> num;
			int tmp = i;
			// i�� �� �ڸ����� ���Ϳ� ����
			while (tmp) {
				num.push_back(tmp % 10);
				tmp /= 10;
			}
			// �Ӹ�������� �ľ�
			int l = 0, r = len - 1, flag = 0;
			while (l <= r) {
				if (num[l] != num[r]) {
					flag = 1;
					break;
				}
				l++;
				r--;
			}
			if (!flag) {
				cout << i;
				break;
			}
		}
	}
}