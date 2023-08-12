#include <bits/stdc++.h>
using namespace std;
bool A[1001] = {1,1,0};
int main() {
	int N, K, i, j, cnt = 0;
	cin >> N >> K;
	if (K == 1) {
		cout << 2;
		return 0;
	}
	for (i = 2; i <= N; i++) {
		if (!A[i]) {
			cnt++;
			if (cnt == K) {
				cout << i;
				break;
			}
			for (j = 2; i * j <= N; j++) {
				if (!A[i * j]) {
					A[i * j] = 1;
					cnt++;
					if (cnt == K) {
						cout << i * j;
					}
				}
			}
		}
	}
}