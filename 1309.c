#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int pL, pR, pO, sum;
	int L = 1, R = 1, O = 1;
	while (--N) {
		pL = L;
		pR = R;
		pO = O;
		L = (pR + pO) % 9901;
		R = (pL + pO) % 9901;
		O = (pL + pR + pO) % 9901;
	}
	sum = (L + R + O) % 9901;
	printf("%d", sum);
	return 0;
}