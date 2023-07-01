#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void find(int N, int r, int c);
int order = 0;

int main() {
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	find(N, r, c);
	printf("%d", order);
	return 0;
}

void find(int N, int r, int c) {
	if (N != 0) {
		int width = 1, size = 1;
		for (int i = 1; i < N; i++) {
			width *= 2;
			size *= 4;
		}
		if (r < width) {
			if (c < width) {
				find(N - 1, r, c);
			}
			else {
				order += size;
				find(N - 1, r, c - width);
			}
		}
		else {
			if (c < width) {
				order += 2 * size;
				find(N - 1, r - width, c);
			}
			else {
				order += 3 * size;
				find(N - 1, r - width, c - width);
			}
		}
	}
}