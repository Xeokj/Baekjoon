#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++)
			printf("*");
		for (j = i; j < N; j++)
			printf("  ");
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
	for (i = 1; i < N; i++) {
		for (j = i; j < N; j++)
			printf("*");
		for (j = 0; j < i; j++)
			printf("  ");
		for (j = i; j < N; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}