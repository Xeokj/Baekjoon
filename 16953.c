#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A, B;
int cnt = 0;
int found = 0;
int find(int A);

int main() {
	scanf("%d %d", &A, &B);
	find(A);
	if (!found)
		printf("-1");
	return 0;
}

int find(int A) {
	cnt++;
	if (A == B) {
		found = 1;
		printf("%d", cnt);
		return;
	}
	else if (A > B || A >= 500000000)
		return;
	else {
		find(A * 2);
		cnt--;
		if (A >= 100000000)
			return;
		find(A * 10 + 1);
		cnt--;
	}
}