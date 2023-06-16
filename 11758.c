#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int i, sum1 = 0, sum2 = 0;
	int point[3][2];
	for (i = 0; i < 3; i++)
		scanf("%d %d", &point[i][0], &point[i][1]);
	
	for (i = 0; i < 3; i++) {
		sum1 += point[i][0] * point[(i + 1) % 3][1];
		sum2 += point[i][1] * point[(i + 1) % 3][0];
	}
	
	if (sum1 - sum2 > 0)
		printf("1");
	else if (sum1 - sum2 < 0)
		printf("-1");
	else
		printf("0");
	return 0;
}