#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int ppow(int a, int b);

int main() {
	int N;
	long long ans = 0;
	scanf("%d", &N);
	int temp = N, cnt = 0;	// cnt: N이 몇 자리 수인지

	while (temp) {
		cnt++;
		temp /= 10;
	}

	int w = ppow(10, cnt - 1);
	temp = N % w + 1;
	temp *= cnt;
	ans = ans + (long long)temp;
	
	temp = N / w - 1;
	temp = temp * w * cnt;
	ans = ans + (long long)temp;
	cnt--;

	while (cnt) {
		w = ppow(10, cnt - 1);
		temp = w * 9 * cnt;
		ans += temp;
		cnt--;
	}

	printf("%lld", ans);
	return 0;
}


int ppow(int a, int b) {
	int res = 1;
	while (b) {
		res *= a;
		b--;
	}
	return res;
}