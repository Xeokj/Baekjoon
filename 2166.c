#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, i, j;
	scanf("%d", &N);
	double* x = (double*)calloc(N, sizeof(double));
	double* y = (double*)calloc(N, sizeof(double));

	for (i = 0; i < N; i++)
		scanf("%lf %lf", &x[i], &y[i]);

	double sum1 = 0, sum2 = 0, Area;
	for (i = 0; i < N - 1; i++) {
		sum1 += x[i] * y[i + 1];
		sum2 += x[i + 1] * y[i];
	}
	sum1 += x[N - 1] * y[0];
	sum2 += x[0] * y[N - 1];
	
	Area = (sum1 - sum2) / 2;
	if (Area < 0)
		Area = -Area;

	printf("%0.1f", Area);
	free(x);
	free(y);
	return 0;
}