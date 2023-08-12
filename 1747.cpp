#include <bits/stdc++.h>
#define MAX 1100000
using namespace std;
bool A[MAX] = {1,1,0};
int main() {
	int N, i, j;
	cin >> N;
	// 에라토스테네스의 체
	for (i = 2; i <= sqrt(MAX); i++) {
		for (j = 2; i * j <= MAX; j++)
			A[i * j] = 1;
	}
	for (i = N; i < MAX; i++) {
		if (!A[i]) {
			// i가 몇 자리 수인지 파악
			int len = 7, w = 1000000;
			while (!(i / w)) {
				w /= 10;
				len--;
			}
			vector<int> num;
			int tmp = i;
			// i의 각 자릿수를 벡터에 저장
			while (tmp) {
				num.push_back(tmp % 10);
				tmp /= 10;
			}
			// 팰린드롬인지 파악
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