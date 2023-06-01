#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)calloc(N, sizeof(int));
	int i = 0, cnt = N;
	while (cnt > 1) {
		arr[i] = -1;
		i++;
		i %= N;
		cnt--;
		while (arr[i] == -1) {
			i++;
			i %= N;
		}
		if (cnt == 1)	break;
		i++;
		i %= N;
		while (arr[i] == -1) {
			i++;
			i %= N;
		}
	}
	printf("%d", i + 1);
	free(arr);
	return 0;
}